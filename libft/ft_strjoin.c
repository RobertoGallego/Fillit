/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmorgan- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 18:29:15 by pmorgan-          #+#    #+#             */
/*   Updated: 2018/12/03 14:41:12 by pmorgan-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*joint_str;
	size_t	i;

	if (!s1 || !s2)
		return (NULL);
	if (!(joint_str = (char*)malloc(ft_strlen(s1) + ft_strlen(s2) + 1)))
		return (NULL);
	i = 0;
	while (*s1)
		joint_str[i++] = *s1++;
	while (*s2)
		joint_str[i++] = *s2++;
	joint_str[i] = '\0';
	return (joint_str);
}
