/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsandshr <dsandshr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 21:09:53 by dsandshr          #+#    #+#             */
/*   Updated: 2020/05/02 16:17:20 by dsandshr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(char const *haystack, char const *needle)
{
	unsigned int i;

	if (!*needle)
		return ((char *)haystack);
	while (*haystack)
	{
		i = 0;
		while (haystack[i] == needle[i])
		{
			++i;
			if (!needle[i])
				return ((char *)haystack);
		}
		++haystack;
	}
	return (NULL);
}
