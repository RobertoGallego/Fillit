/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmorgan- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 17:37:29 by pmorgan-          #+#    #+#             */
/*   Updated: 2018/12/03 14:40:17 by pmorgan-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*sub_str;

	if (!s)
		return (NULL);
	if (!(sub_str = (char*)malloc(len + 1)))
		return (NULL);
	sub_str[len] = '\0';
	while (--len + 1)
		sub_str[len] = s[start + len];
	return (sub_str);
}
