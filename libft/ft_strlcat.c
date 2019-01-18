/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmorgan- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/01 18:52:11 by pmorgan-          #+#    #+#             */
/*   Updated: 2018/12/01 18:52:16 by pmorgan-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t			ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t		i;
	size_t		td;
	size_t		ts;

	i = 0;
	td = ft_strlen(dest);
	ts = ft_strlen(src);
	if (td >= size)
		return (size + ts);
	while (src[i] && (td + i) < (size - 1))
	{
		dest[td + i] = src[i];
		i++;
	}
	dest[td + i] = '\0';
	return (td + ts);
}
