/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsandshr <dsandshr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 16:18:07 by dsandshr          #+#    #+#             */
/*   Updated: 2020/05/02 16:04:48 by dsandshr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_funcs.h"

int		ft_strnequ(char const *s1, char const *s2, size_t n)
{
	if (s1 != s2)
	{
		if (!s1 || !s2)
			return (0);
		while ((*s1 || *s2) && n)
		{
			if (*s1 != *s2)
				return (0);
			++s1;
			++s2;
			--n;
		}
	}
	return (1);
}
