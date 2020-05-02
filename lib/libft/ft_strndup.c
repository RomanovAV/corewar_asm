/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsandshr <dsandshr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 21:39:45 by dsandshr          #+#    #+#             */
/*   Updated: 2020/05/02 16:17:00 by dsandshr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(const char *s, size_t n)
{
	size_t	len;
	char	*new;

	len = ft_strlen(s);
	if (n > len)
		n = len;
	if (!(new = (char *)malloc(sizeof(char) * (n + 1))))
		return (NULL);
	*(new + n) = 0;
	while (n)
	{
		--n;
		*(new + n) = *(s + n);
	}
	return (new);
}
