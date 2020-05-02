/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsandshr <dsandshr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 19:01:47 by dsandshr          #+#    #+#             */
/*   Updated: 2020/05/02 16:04:33 by dsandshr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_funcs.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char *sc;

	sc = (unsigned char *)s;
	while (n)
	{
		--n;
		*sc = (unsigned char)c;
		++sc;
	}
	return (s);
}
