/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsandshr <dsandshr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 21:18:19 by dsandshr          #+#    #+#             */
/*   Updated: 2020/05/02 16:16:08 by dsandshr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(char const *s)
{
	char *new;
	char *new0;

	if (!(new = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1))))
		return (NULL);
	new0 = new;
	while (*s)
	{
		*new = *s;
		++new;
		++s;
	}
	*new = 0;
	return (new0);
}
