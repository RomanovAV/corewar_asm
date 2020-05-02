/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsandshr <dsandshr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 21:55:24 by dsandshr          #+#    #+#             */
/*   Updated: 2020/05/02 16:04:22 by dsandshr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_funcs.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char *sc;

	sc = (unsigned char *)s;
	while (n)
	{
		--n;
		*sc = 0;
		++sc;
	}
}
