/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsandshr <dsandshr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/05 10:43:41 by dsandshr          #+#    #+#             */
/*   Updated: 2020/05/06 11:09:38 by dsandshr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static int	check_labels(t_label *list, char *label_link)
{
	while (list)
	{
		if (ft_strequ(list->label_name, label_link))
			return (1);
		list = list->next;
	}
	return (0);
}

static int	find_label(t_opcode *head, char *label_link)
{
	t_opcode	*prog;
	int			bytes;

	prog = head->prev;
	bytes = 0;
	while (prog)
	{
		bytes -= prog->size;
		if (check_labels(prog->labels, label_link))
			return (bytes);
		prog = prog->prev;
	}
	prog = head;
	bytes = 0;
	while (prog)
	{
		if (check_labels(prog->labels, label_link))
			return (bytes);
		bytes += prog->size;
		prog = prog->next;
	}
	ft_printf("Label \"%s\" ", label_link);
	error("not found", 0);
	return (0);

static void	set_links_values(t_opcode *prog)
{
	int i;

	while (prog)
	{
		i = 0;
		while (i < 3)
		{
			if (prog->param[i] && prog->param[i]->link)
			{
				prog->param[i]->value = find_label(prog, prog->param[i]->link);
				free(prog->param[i]->link);
			}
			++i;
		}
		prog = prog->next;
	}
}

static int	params_size(t_opcode_param **params, t_opcode_type type)
{
	size_t	size;
	int		i;

	size = 0;
	i = 0;
	while (i < 3)
	{
		if (params[i])
		{
			if (params[i]->type == crw_registry)
				size += T_REG;
			else if (params[i]->type == crw_indirect || type == crw_zjmp
				|| type == crw_ldi || type == crw_sti || type == crw_fork
				|| type == crw_lld || type == crw_lldi || type == crw_lfork)
				size += T_DIR;
			else
				size += T_IND;
		}
		++i;
	}
	return (size);
}

void	calculate_size(t_champion *champ)
{
	t_opcode *prog;

	champ->code_size = 0;
	prog = champ->program;
	while (prog)
	{
		if (prog->type != crw_undef_code)
		{
			prog->size = 1 + (prog->type != crw_live && prog->type != crw_zjmp
						&& prog->type != crw_fork && prog->type != crw_lfork);
			prog->size += params_size(prog->param, prog->type);
			champ->code_size += prog->size;
		}
		prog = prog->next;
	}
	set_links_value(champ->program);
}