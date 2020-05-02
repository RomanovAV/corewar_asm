/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsandshr <dsandshr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 22:14:21 by dsandshr          #+#    #+#             */
/*   Updated: 2020/05/02 16:15:44 by dsandshr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcat(char *dst, char const *src)
{
	char *dst0;

	dst0 = dst;
	while (*dst)
		++dst;
	while (*src)
	{
		*dst = *src;
		++dst;
		++src;
	}
	*dst = 0;
	return (dst0);
}
