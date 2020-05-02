/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsandshr <dsandshr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 21:55:36 by dsandshr          #+#    #+#             */
/*   Updated: 2020/05/02 16:16:56 by dsandshr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t n)
{
	char *dst0;

	dst0 = dst;
	while (*src && n)
	{
		--n;
		*dst = *src;
		++dst;
		++src;
	}
	while (n)
	{
		--n;
		*dst = 0;
		++dst;
	}
	return (dst0);
}
