/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsandshr <dsandshr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/04 13:27:19 by dsandshr          #+#    #+#             */
/*   Updated: 2020/05/04 14:13:29 by dsandshr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int g_cur_line;
int g_cur_col;

void		error(char *err, int type)
{
	if (type)
	{
		ft_printf("%s [%d:%d]\n", err, g_cur_line, g_cur_col);
		errno = EINVAL;
	}
	else
		ft_printf("%s\n", err);
	exit(errno);
}

static void	faq(void)
{
	ft_printf("Usage: asm [-df] [file]\n"
			"\tif no -d flag specified asm will assemble file.s\n"
			"\tuse -d for dissamble file.cor\n"
			"\twith -f flag asm will output into current directory\n");
	exit(1);
}

static int get_flag(char *str)
{
	int flag;

	++str;
	flag = 0;
	while (*str)
	{
		if (*str == 'd')
			flag |= F_DISASSEMBLE;
		else if (*str == 'f')
			flag |= F_OUTPUT_LOCAL;
		else
			faq();
		str++;
	}
	return (flag);
}

int main(int ac, char **av)
{
	int	flag;
	int	index;

	if (ac == 1)
		faq();
	index = 1;
	while (index < ac)
	{
		flag = av[1][0] == "-" ? get_flag(av[index++]) : 0;
		if (index == ac)
			error("file not specified", 0);
		pricess(av[index], flag);
		++index;
	}
	return (0);
}