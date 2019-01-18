/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmorgan- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/28 14:56:27 by pmorgan-          #+#    #+#             */
/*   Updated: 2019/01/02 14:09:28 by pmorgan-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	Join N bytes of the char array s2 to the Null terminated string s1.
*/

#include "libft.h"

char	*ft_strnjoin(char const *s1, char const *s2, size_t n)
{
	char	*joint_str;
	int		joint_size;
	size_t	i;

	if (!s1 || !s2)
		return (NULL);
	joint_size = ft_strlen(s1) + ft_minint(ft_strlen(s2), (int)n) + 1;
	if (!(joint_str = (char*)malloc(joint_size)))
		return (NULL);
	i = 0;
	while (*s1)
		joint_str[i++] = *s1++;
	while (*s2 && n--)
		joint_str[i++] = *s2++;
	joint_str[i] = '\0';
	return (joint_str);
}
