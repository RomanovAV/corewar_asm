/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsandshr <dsandshr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 15:22:48 by dsandshr          #+#    #+#             */
/*   Updated: 2020/05/02 16:15:25 by dsandshr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long tmp;

	if (!n)
		write(fd, "0", 1);
	else
	{
		tmp = (n < 0) ? -1 : 1;
		while (n)
		{
			tmp = tmp * 10 + n % 10;
			n /= 10;
		}
		if (tmp < 0)
		{
			write(fd, "-", 1);
			tmp = ~tmp + 1;
		}
		while (tmp != 1)
		{
			n = tmp % 10 + '0';
			write(fd, &n, 1);
			tmp /= 10;
		}
	}
}
