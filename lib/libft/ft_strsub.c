/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsandshr <dsandshr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 16:22:46 by dsandshr          #+#    #+#             */
/*   Updated: 2020/05/02 16:17:23 by dsandshr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char *fresh;

	if (!s)
		return (NULL);
	if (!(fresh = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	*(fresh + len) = 0;
	s += start + len;
	while (len)
	{
		--len;
		--s;
		*(fresh + len) = *s;
	}
	return (fresh);
}
