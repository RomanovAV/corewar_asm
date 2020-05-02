/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsandshr <dsandshr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 15:58:06 by dsandshr          #+#    #+#             */
/*   Updated: 2020/05/02 16:16:47 by dsandshr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	i;
	char	*fresh;

	if (!s || !f)
		return (NULL);
	i = ft_strlen(s);
	if (!(fresh = (char *)malloc(sizeof(char) * (i + 1))))
		return (NULL);
	*(fresh + i) = 0;
	while (i)
	{
		--i;
		*(fresh + i) = f(i, s[i]);
	}
	return (fresh);
}
