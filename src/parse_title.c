/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_title.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smorty <smorty@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/15 20:20:13 by tlorine           #+#    #+#             */
/*   Updated: 2019/09/26 23:04:33 by tlorine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static char	*get_string(int fd)
{
	char	*s;
	int		size;
	char	buf;

	while (read(fd, &buf, 1) > 0 && buf != '"')
		if (!IS_BLANK(buf))
			error("Syntax error", 1);
	size = get_string_size(fd);
	if (!(s = (char *)malloc(sizeof(char) * (size + 1))))
		error(strerror(errno), 0);
	if (read(fd, s, size + 1) != size + 1)
		errno = EIO;
	s[size] = 0;
	if (errno)
		error(strerror(errno), 0);
	return (s);
}

static int	check_token(const char *s, ssize_t size, int fd)
{
	char	buf[size + 1];
	int		rd;

	if ((rd = read(fd, buf, size)) < 0)
		error(strerror(errno), 0);
	if (rd != size)
		error("Syntax error: wrong title", 0);
	buf[size] = 0;
	if (ft_strequ(s, buf))
		return (1);
	lseek(fd, -size, SEEK_CUR);
	if (errno)
		error(strerror(errno), 0);
	return (0);
}

static void	skip_until_token(int fd)
{
	char buf;

	while (read(fd, &buf, 1) > 0)
	{
		if (buf == COMMENT_CHAR || buf == COMMENT_CHAR_ALT)
		{
			while (read(fd, &buf, 1) > 0 && buf != '\n')
				;
			++g_cur_line;
		}
		else if (buf == '\n')
			++g_cur_line;
		else if (!IS_BLANK(buf))
			break ;
	}
	lseek(fd, -1, SEEK_CUR);
	if (errno)
		error(strerror(errno), 0);
}

void		parse_title(t_champion *champ, int fd)
{
	champ->name = NULL;
	champ->comment = NULL;

    while (!champ->name || !champ->comment)
	{
		skip_until_token(fd);
		if (!champ->name && check_token(NAME_CMD_STRING,
									sizeof(NAME_CMD_STRING) - 1, fd))
			champ->name = get_string(fd);
		else if (!champ->comment && check_token(COMMENT_CMD_STRING,
									sizeof(COMMENT_CMD_STRING) - 1, fd))
			champ->comment = get_string(fd);
		else
			error("Syntax error: wrong title", 1);
	}
	if (ft_strlen(champ->name) > PROG_NAME_LENGTH)
		error("Error: name is too big", 0);
	if (ft_strlen(champ->comment) > COMMENT_LENGTH)
		error("Error: commentary is too big", 0);
}