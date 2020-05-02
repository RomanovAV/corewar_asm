/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsandshr <dsandshr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 20:28:04 by dsandshr          #+#    #+#             */
/*   Updated: 2020/05/02 16:14:50 by dsandshr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(void const *s, int c, size_t n)
{
	while (n)
	{
		--n;
		if (*(unsigned char *)s == (unsigned char)c)
			return ((void *)s);
		++s;
	}
	return (NULL);
}
