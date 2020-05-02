/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsandshr <dsandshr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 14:54:53 by dsandshr          #+#    #+#             */
/*   Updated: 2020/05/02 16:17:27 by dsandshr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	size_t	i;
	char	*new;

	if (!s)
		return (NULL);
	i = 0;
	while (*s == ' ' || *s == '\n' || *s == '\t')
		++s;
	while (s[i])
		++i;
	while (i && (s[i - 1] == ' ' || s[i - 1] == '\n' || s[i - 1] == '\t'))
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
