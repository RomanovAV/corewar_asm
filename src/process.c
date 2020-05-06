/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsandshr <dsandshr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/04 13:30:43 by dsandshr          #+#    #+#             */
/*   Updated: 2020/05/06 11:02:57 by dsandshr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

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

static int	new_file(t_champion *champion, char *name, int flag)
{
	char	*new_file;
	int		fd;

	new_file = get_new_filename(name, flag);
	if ((fd = open(new_file, O_CREAT | O_WRONLY | O_TRUNC,
	S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH)) < 0)
		error(strerror(errno), 0);
	if (flag & F_DISASSEMBLE)
		ft_printf("Writing output champion to %s\n", new_file);
	else
	{
		if (!(write(fd, champion->byte_code, champion->code_size)))
			error(strerror(errno), 0);
		close(fd);
		ft_printf("Writing output program to %s\n", new_file);
	}
	free(new_file);
	return (fd);
}

static int	get_fd(char *file_name, int flag)
{
	char *p;
	int fd;

	p = file_name;
	while (*p)
		++p;
	if (flag & F_DISASSEMBLE ? p - file_name < 5 || !ft_strequ(p - 4, ".cor")
	: p - file_name < 3 || !ft_strequ(p - 2, ".s"))
		error("Wrong filename (need .s or .cor with -d flag)", 0);
	if ((fd = open(file_name, O_RDONLY)) < 0)
		error(strerror(errno), 0);
	return (fd);
}

void		process(char *str, int flag)
{
	t_champion *champ;

	if (flag & F_DISASSEMBLE)
		disassemble();
	else
	{
		champ = parse_file(get_fd(str, flag));
		calculate_size(champ)
		assemble(champ);
		new_file(champ, str, flag);
		clean(champ);
	}
	return (0)
}