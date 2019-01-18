/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmorgan- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 16:28:24 by pmorgan-          #+#    #+#             */
/*   Updated: 2018/12/01 16:33:29 by pmorgan-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t			i;
	unsigned char	*dst_cast;
	unsigned char	*src_cast;

	dst_cast = (unsigned char*)dst;
	src_cast = (unsigned char*)src;
	i = 0;
	while (i < n)
	{
		dst_cast[i] = src_cast[i];
		if (src_cast[i] == (unsigned char)c)
			return ((void*)(dst_cast + i + 1));
		i++;
	}
	return (0);
}
