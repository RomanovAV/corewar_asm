/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsandshr <dsandshr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 21:51:44 by dsandshr          #+#    #+#             */
/*   Updated: 2020/05/02 16:16:42 by dsandshr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char *fresh;
	char *fresh0;

	if (!s || !f)
		return (NULL);
	if (!(fresh = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1))))
		return (NULL);
	fresh0 = fresh;
	while (*s)
	{
		*fresh = f(*s);
		++fresh;
		++s;
	}
	*fresh = 0;
	return (fresh0);
}
