/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsandshr <dsandshr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 21:03:03 by dsandshr          #+#    #+#             */
/*   Updated: 2020/05/02 16:17:14 by dsandshr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	const char *s0;

	s0 = s;
	while (*s)
		++s;
	if (!c)
		return ((char *)s);
	while (s != s0)
	{
		--s;
		if (*s == (char)c)
			return ((char *)s);
	}
	return (NULL);
}
