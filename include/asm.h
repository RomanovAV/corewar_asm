/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsandshr <dsandshr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/19 15:23:31 by dsandshr          #+#    #+#             */
/*   Updated: 2020/05/19 15:47:58 by dsandshr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_H
# define ASM_H

# include <unistd.h>
# include <fcntl.h>
# include <errno.h>
# include "libft.h"
# include "op.h"
# include "ft_printf.h"

# define BUFF_SIZE 16

# define IS_BLANK(c) (c == ' ' || c == '\t')
# define IS_DIGIT(c) (c >= '0' && c <= '9')

# define F_DISASSEMBLE 1
# define F_OUTPUT_LOCAL 2

extern int		g_cur_line;
extern int		g_cur_col;

typedef enum	e_opcode_type
{
	crw_undef_code,
	crw_live,
	crw_ld,
	crw_st,
	crw_add,
	crw_sub,
	crw_and,
	crw_or,
	crw_xor,
	crw_zjmp,
	crw_ldi,
	crw_sti,
	crw_fork,
	crw_lld,
	crw_lldi,
	crw_lfork,
	crw_aff
}				t_opcode_type;

typedef enum	e_param_type
{
	crw_undef_param,
	crw_registry,
	crw_direct,
	crw_indirect
}				t_param_type;

typedef struct	s_opcode_param
{
	char			*link;
	t_param_type	type;
	int				value;
}				t_opcode_param;

typedef struct	s_label
{
	char			*label_name;
	struct s_label	*next;
}				t_label;

typedef struct	s_opcode
{
	t_label			*labels;
	t_opcode_param	*param[3];
	t_opcode_type	type;
	size_t			size;
	unsigned char	param_code;
	struct s_opcode	*next;
	struct s_opcode	*prev;
}				t_opcode;

typedef struct	s_champion
{
	char			*name;
	char			*comment;
	t_opcode		*program;
	unsigned char	*byte_code;
	size_t			code_size;
}				t_champion;

void			error(char *err, int type);
void			process(char *str, int flag);
t_champion		*parse_file(int fd);
void			parse_title(t_champion *champ, int fd);
void			assemble(t_champion *champ);
void			calculate_size(t_champion *champ);
void			parse_label(t_opcode *opcode, char **line);
void			parse_opcode(t_opcode *opcode, char *line);
t_opcode_param	*parse_parameter(char *line);
char			*read_input(int fd);
void			skip_whitespaces(char **line);
void			disassemble(int fd, int fd_out);

#endif