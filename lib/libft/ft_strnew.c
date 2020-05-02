/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsandshr <dsandshr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 21:09:05 by dsandshr          #+#    #+#             */
/*   Updated: 2020/05/02 16:17:07 by dsandshr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char *fresh;

	if (!(fresh = (char *)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	ft_bzero(fresh, size + 1);
	return (fresh);
}
