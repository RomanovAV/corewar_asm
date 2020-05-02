/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsandshr <dsandshr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 21:58:52 by dsandshr          #+#    #+#             */
/*   Updated: 2020/05/02 16:16:35 by dsandshr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t n)
{
	const char *begin;

	begin = src;
	if (dst && src)
	{
		if (n)
		{
			while ((n - 1) && *src)
			{
				*dst = *src;
				++dst;
				++src;
				--n;
			}
			*dst = 0;
		}
		while (*src)
			++src;
	}
	return (src - begin);
}
