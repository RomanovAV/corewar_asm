/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assemble.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsandshr <dsandshr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/06 11:11:05 by dsandshr          #+#    #+#             */
/*   Updated: 2020/05/06 11:13:27 by dsandshr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static void	assemble_text(unsigned char **code, char *text, size_t size)
{
	while (*text && size--)
		*(*code)++ = *text++;
	while (size--)
		++(*code);
	size = 4;
	while (size--)
		++(*code);
}

static void	assemble_number(unsigned char **code, int number)
{
	*(*code)++ = (number >> 24) & 0xff;
	*(*code)++ = (number >> 16) & 0xff;
	*(*code)++ = (number >> 8) & 0xff;
	*(*code)++ = number & 0xff;
}

static void	assemble_params(unsigned char **code,
							t_opcode_param **params, t_opcode_type type)
{
	int i;

	i = 0;
	while (i < 3)
	{
		if (params[i])
		{
			if (params[i]->type == crw_registry)
				*(*code)++ = params[i]->value;
			else if (params[i]->type == crw_indirect || type == crw_zjmp
				|| type == crw_ldi || type == crw_sti || type == crw_fork
				|| type == crw_lld || type == crw_lldi || type == crw_lfork)
			{
				*(*code)++ = params[i]->value >> 8;
				*(*code)++ = params[i]->value & 0xff;
			}
			else
				assemble_number(code, params[i]->value);
		}
		++i;
	}
}

static void	assemble_code(unsigned char *code, t_opcode *program)
{
	while (program)
	{
		*code++ = program->type;
		if (program->param_code != 128)
			*code++ = program->param_code;
		assemble_params(&code, program->param, program->type);
		program = program->next;
	}
}

void		assemble(t_champion *champ)
{
	unsigned char	*code;
	size_t			size;

	size = PROG_NAME_LENGTH + COMMENT_LENGTH + champ->code_size + 16;
	if (!(code = (unsigned char *)malloc(sizeof(char) * size)))
		error(strerror(errno), 0);
	champ->byte_code = code;
	ft_bzero(code, size);
	assemble_number(&code, COREWAR_EXEC_MAGIC);
	assemble_text(&code, champ->name, PROG_NAME_LENGTH);
	assemble_number(&code, champ->code_size);
	assemble_text(&code, champ->comment, COMMENT_LENGTH);
	assemble_code(code, champ->program);
	champ->code_size = size;
}