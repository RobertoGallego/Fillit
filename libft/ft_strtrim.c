/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmorgan- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 19:01:53 by pmorgan-          #+#    #+#             */
/*   Updated: 2018/12/03 14:41:57 by pmorgan-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char	*tr_str;
	int		tr_len;

	if (!s)
		return (NULL);
	tr_len = ft_strlen(s) - 1;
	while (s[tr_len] == ' ' || s[tr_len] == '\n' || s[tr_len] == '\t')
		tr_len--;
	if (tr_len < 0)
		return (ft_strnew(0));
	while (*s == ' ' || *s == '\n' || *s == '\t')
	{
		tr_len--;
		s++;
	}
	tr_len++;
	if (!(tr_str = (char*)malloc(tr_len + 1)))
		return (NULL);
	tr_str[tr_len] = '\0';
	while (tr_len)
	{
		tr_len--;
		tr_str[tr_len] = s[tr_len];
	}
	return (tr_str);
}
