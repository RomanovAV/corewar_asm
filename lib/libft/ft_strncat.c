/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsandshr <dsandshr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 16:13:32 by dsandshr          #+#    #+#             */
/*   Updated: 2020/05/02 16:16:50 by dsandshr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *dst, char const *src, size_t n)
{
	char *dst0;

	dst0 = dst;
	while (*dst)
		++dst;
	while (*src && n)
	{
		--n;
		*dst = *src;
		++dst;
		++src;
	}
	*dst = 0;
	return (dst0);
}
