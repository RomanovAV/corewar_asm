/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsandshr <dsandshr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 19:10:42 by dsandshr          #+#    #+#             */
/*   Updated: 2020/05/02 16:14:17 by dsandshr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	unsigned int	size;
	long			tmp;
	char			*fresh;

	tmp = n;
	size = (n <= 0);
	while (n)
	{
		n /= 10;
		++size;
	}
	if (!(fresh = (char *)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	*(fresh + size) = 0;
	*fresh = (tmp < 0 ? '-' : '0');
	if (tmp < 0)
		tmp = ~tmp + 1;
	while (tmp)
	{
		--size;
		*(fresh + size) = tmp % 10 + '0';
		tmp /= 10;
	}
	return (fresh);
}
