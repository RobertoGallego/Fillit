/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmorgan- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 16:55:58 by pmorgan-          #+#    #+#             */
/*   Updated: 2018/12/03 14:31:24 by pmorgan-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*f_output;
	size_t	i;

	if (!f)
		return (NULL);
	if (!(f_output = (char*)malloc(ft_strlen(s) + 1)))
		return (NULL);
	i = 0;
	while (s[i])
	{
		f_output[i] = f(s[i]);
		i++;
	}
	f_output[i] = '\0';
	return (f_output);
}
