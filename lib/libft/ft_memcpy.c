/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsandshr <dsandshr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 17:17:58 by dsandshr          #+#    #+#             */
/*   Updated: 2020/05/02 16:14:55 by dsandshr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, void const *src, size_t n)
{
	unsigned const char	*s;
	unsigned char		*d;

	if (dst != src)
	{
		s = (unsigned const char *)src;
		d = (unsigned char *)dst;
		while (n)
		{
			--n;
			*d = *s;
			++d;
			++s;
		}
	}
	return (dst);
}
