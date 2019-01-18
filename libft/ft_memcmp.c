/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmorgan- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 11:15:07 by pmorgan-          #+#    #+#             */
/*   Updated: 2018/11/29 16:11:52 by pmorgan-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*chs1;
	unsigned char	*chs2;

	chs1 = (unsigned char*)s1;
	chs2 = (unsigned char*)s2;
	i = -1;
	while (++i < n)
		if (chs1[i] != chs2[i])
			return (chs1[i] - chs2[i]);
	return (0);
}
