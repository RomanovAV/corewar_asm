/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrimc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsandshr <dsandshr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/18 17:31:34 by dsandshr          #+#    #+#             */
/*   Updated: 2020/05/02 16:18:24 by dsandshr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrimc(char const *s, char c)
{
	size_t	i;
	char	*new;

	if (!s)
		return (NULL);
	i = 0;
	while (*s == c)
		++s;
	while (s[i])
		++i;
	while (i && s[i - 1] == c)
		--i;
	if (!(new = (char *)malloc(sizeof(char) * (i + 1))))
		return (NULL);
	*(new + i) = 0;
	while (i)
	{
		--i;
		*(new + i) = *(s + i);
	}
	return (new);
}
