/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsandshr <dsandshr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 16:32:54 by dsandshr          #+#    #+#             */
/*   Updated: 2020/05/02 16:16:30 by dsandshr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, char const *src, size_t n)
{
	size_t len;

	len = ft_strlen(dst);
	if (n < len)
		return (n + ft_strlen(src));
	dst += len;
	n -= len;
	while (*src)
	{
		if (n > 1)
		{
			--n;
			*dst = *src;
			++dst;
		}
		++src;
		++len;
	}
	*dst = 0;
	return (len);
}
