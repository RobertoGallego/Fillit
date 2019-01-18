/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmorgan- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/07 11:40:44 by pmorgan-          #+#    #+#             */
/*   Updated: 2018/12/01 18:03:25 by pmorgan-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned int i;

	if (!n)
		return (0);
	i = 0;
	while (s1[i] == s2[i] && s1[i] && s2[i] && i < (n - 1))
		++i;
	return ((int)((unsigned char)s1[i] - (unsigned char)s2[i]));
}
