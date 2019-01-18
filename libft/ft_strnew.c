/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmorgan- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 16:23:24 by pmorgan-          #+#    #+#             */
/*   Updated: 2018/12/01 18:54:50 by pmorgan-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*mem_area;

	if (!(mem_area = (char*)ft_memalloc(size + 1)))
		return (NULL);
	return ((char*)mem_area);
}
