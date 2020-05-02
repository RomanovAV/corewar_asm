/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsandshr <dsandshr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 16:04:10 by dsandshr          #+#    #+#             */
/*   Updated: 2020/05/02 16:14:43 by dsandshr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void *fresh;

	if (!(fresh = malloc(sizeof(char) * size)))
		return (NULL);
	ft_bzero(fresh, size);
	return (fresh);
}
