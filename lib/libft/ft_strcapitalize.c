/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsandshr <dsandshr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 16:53:32 by dsandshr          #+#    #+#             */
/*   Updated: 2020/05/02 16:15:42 by dsandshr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcapitalize(char *s)
{
	char	*begin;

	begin = s;
	if (s)
	{
		if (ft_islower(*s))
			*s -= 32;
		++s;
		while (*s)
		{
			if (ft_islower(*s) && !ft_isalnum(*(s - 1)))
				*s -= 32;
			else if (ft_isupper(*s) && ft_isalnum(*(s - 1)))
				*s += 32;
			++s;
		}
	}
	return (begin);
}
