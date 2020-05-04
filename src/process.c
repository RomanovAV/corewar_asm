/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsandshr <dsandshr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/04 13:30:43 by dsandshr          #+#    #+#             */
/*   Updated: 2020/05/04 13:59:28 by dsandshr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

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
		assemble(champ);
		clean(champ);
	}
}