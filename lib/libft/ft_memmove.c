/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsandshr <dsandshr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 19:35:37 by dsandshr          #+#    #+#             */
/*   Updated: 2020/05/02 16:15:03 by dsandshr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	char *s;
	char *d;

	if (src != dst)
	{
		d = (char *)dst;
		s = (char *)src;
		if (src > dst)
			while (n)
			{
				--n;
				*d = *s;
				++d;
				++s;
			}
		else
			while (n)
			{
				--n;
				*(d + n) = *(s + n);
			}
	}
	return (dst);
}
