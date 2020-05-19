/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsandshr <dsandshr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/04 13:30:43 by dsandshr          #+#    #+#             */
/*   Updated: 2020/05/19 16:05:52 by dsandshr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static int	open_file(char *file_name, int flag)
{
	char	*p;
	int		fd;

	p = file_name;
	while (*p)
		++p;
	if (flag & F_DISASSEMBLE ?
		p - file_name < 5 || !ft_strequ(p - 4, ".cor")
		: p - file_name < 3 || !ft_strequ(p - 2, ".s"))
		error("Wrong filename (need .s or .cor with -d flag)", 0);
	if ((fd = open(file_name, O_RDONLY)) < 0)
		error(strerror(errno), 0);
	return (fd);
}

static char	*get_new_filename(char *file_name, int flag)
{
	char	*new;

	new = file_name;
	while (*new)
		++new;
	*(new - (flag & F_DISASSEMBLE ? 4 : 2)) = 0;
	if (flag & F_OUTPUT_LOCAL)
	{
		while (new != file_name && *new != '/')
			--new;
		if (*new == '/')
			++new;
		file_name = new;
	}
	if (!(new = ft_strjoin(file_name, flag & F_DISASSEMBLE ? ".s" : ".cor")))
		error(strerror(errno), 0);
	return (new);
}

static int	build_file(t_champion *champ, char *name, int flag)
{
	char	*new_file;
	mode_t	mode;
	int		fd;

	mode = S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH;
	new_file = get_new_filename(name, flag);
	if ((fd = open(new_file, O_CREAT | O_WRONLY | O_TRUNC, mode)) < 0)
		error(strerror(errno), 0);
	if (flag & F_DISASSEMBLE)
		ft_printf("Writing output champion to %s\n", new_file);
	else
	{
		if (!(write(fd, champ->byte_code, champ->code_size)))
			error(strerror(errno), 0);
		close(fd);
		ft_printf("Writing output program to %s\n", new_file);
	}
	free(new_file);
	return (fd);
}

static void	cleanup(t_champion *champ)
{
	void *clean;

	while (champ->program)
	{
		while (champ->program->labels)
		{
			clean = (t_label *)champ->program->labels;
			free(champ->program->labels->label_name);
			champ->program->labels = champ->program->labels->next;
			free(clean);
		}
		if (champ->program->param[0])
			free(champ->program->param[0]);
		if (champ->program->param[1])
			free(champ->program->param[1]);
		if (champ->program->param[2])
			free(champ->program->param[2]);
		clean = (t_opcode *)champ->program;
		champ->program = champ->program->next;
		free(clean);
	}
	free(champ->name);
	free(champ->comment);
	free(champ->byte_code);
	free(champ);
}

void		process(char *arg, int flag)
{
	t_champion *champ;

	if (flag & F_DISASSEMBLE)
		disassemble(open_file(arg, flag), build_file(NULL, arg, flag));
	else
	{
		champ = parse_file(open_file(arg, flag));
		calculate_size(champ);
		assemble(champ);
		build_file(champ, arg, flag);
		cleanup(champ);
	}
}