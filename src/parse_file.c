/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/04 13:52:43 by dsandshr          #+#    #+#             */
/*   Updated: 2020/05/12 12:23:37 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int g_cur_line;
int g_cur_col;

static t_opcode	*new_element(t_opcode **program)
{
	t_opcode *new;

	if (!(new = (t_opcode *)malloc(sizeof(t_opcode))))
		error(strerror(errno), 0);
	new->next = NULL;
	new->labels = NULL;
	new->type = crw_undef_code;
	new->size = 0;
	new->param_code = 0;
	if ((new->prev = *program))
		(*program)->next = new;
	return (new);
}

void			skip_whitespaces(char **line)
{
	while (**line && IS_BLANK(**line))
	{
		++(*line);
		++g_cur_col;
	}
}

static void		trim_comment(char *line)
{
	while (*line && *line != COMMENT_CHAR && *line != COMMENT_CHAR_ALT)
		++line;
	*line = 0;
}

static void		parse_line(t_opcode **program, char *line)
{
	g_cur_col = 1;
	skip_whitespaces(&line);
	trim_comment(line);
	if (!*line)
		return ;
	if (!(*program) || (*program)->type != crw_undef_code)
		*program = new_element(program);
	parse_label(*program, &line);
	parse_opcode(*program, line);
}

t_champion	*parse_file(int fd)
{
	t_champion	*champ;
	t_opcode	*program;
	char		*line;

	if (!(champ = (t_champion *)malloc(sizeof(t_champion))))
		error(strerror(errno), 0);
	g_cur_line = 1;
	g_cur_col = 1;
	parse_title(champ, fd);
	program = NULL;
	while ((line = read_input(fd)))
	{
		parse_line(&program, line);
		free(line);
		++g_cur_line;
	}
	if (!program)
		error("Error: empty champion", 0);
	while (program->prev)
		program = program->prev;
	champ->program = program;
	close(fd);
	return (champ);
}