/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmorgan- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 17:28:32 by pmorgan-          #+#    #+#             */
/*   Updated: 2018/11/29 14:53:44 by pmorgan-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memmove(void *dest, const void *src, size_t len)
{
	unsigned char	*dest_cast;
	unsigned char	*src_cast;

	if (dest == src || len == 0)
		return (dest);
	dest_cast = (unsigned char*)dest;
	src_cast = (unsigned char*)src;
	if (src_cast < dest_cast)
		while (len--)
			dest_cast[len] = src_cast[len];
	else
		ft_memcpy(dest, src, len);
	return (dest);
}
