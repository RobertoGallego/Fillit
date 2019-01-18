/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmorgan- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 17:30:58 by pmorgan-          #+#    #+#             */
/*   Updated: 2018/12/03 14:52:13 by pmorgan-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*s_cast;

	s_cast = (unsigned char*)s;
	i = 0;
	while (i < n)
	{
		if (s_cast[i] == (unsigned char)c)
			return ((void*)&s[i]);
		i++;
	}
	return (0);
}
