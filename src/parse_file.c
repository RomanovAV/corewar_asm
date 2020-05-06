/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsandshr <dsandshr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/04 13:52:43 by dsandshr          #+#    #+#             */
/*   Updated: 2020/05/06 12:37:06 by dsandshr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

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
	return (champ);
}