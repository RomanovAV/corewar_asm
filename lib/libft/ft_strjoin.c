/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsandshr <dsandshr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 16:54:58 by dsandshr          #+#    #+#             */
/*   Updated: 2020/05/02 16:16:26 by dsandshr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*fresh;
	char	*fresh0;

	if (!s1 || !s2)
		return (NULL);
	fresh = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!fresh)
		return (NULL);
	fresh0 = fresh;
	while (*s1)
	{
		*fresh = *s1;
		++fresh;
		++s1;
	}
	while (*s2)
	{
		*fresh = *s2;
		++fresh;
		++s2;
	}
	*fresh = 0;
	return (fresh0);
}
