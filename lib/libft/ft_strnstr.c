/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsandshr <dsandshr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 21:30:26 by dsandshr          #+#    #+#             */
/*   Updated: 2020/05/02 16:17:10 by dsandshr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t n)
{
	size_t i;

	if (!*needle)
		return ((char *)haystack);
	while (*haystack && n)
	{
		i = 0;
		while (haystack[i] == needle[i] && i < n)
		{
			++i;
			if (!needle[i])
				return ((char *)(haystack));
		}
		++haystack;
		--n;
	}
	return (NULL);
}
