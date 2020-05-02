/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_funcs.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsandshr <dsandshr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 20:54:28 by dsandshr          #+#    #+#             */
/*   Updated: 2020/05/02 16:00:25 by dsandshr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <string.h>
# include <stdlib.h>
# include <unistd.h>

int				ft_atoi(char const *s);
void			ft_bzero(void *s, size_t n);
void			*ft_memset(void *s, int c, size_t n);
size_t			ft_strlen(char const *s);
int				ft_strnequ(char const *s1, char const *s2, size_t n);

#endif
