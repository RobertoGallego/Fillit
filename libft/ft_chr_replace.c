/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_chr_replace.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmorgan- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/11 15:08:01 by pmorgan-          #+#    #+#             */
/*   Updated: 2019/01/11 15:11:18 by pmorgan-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_chr_replace(char *s, char current, char replacement)
{
	while (*s)
	{
		if (*s == current)
			*s = replacement;
		s++;
	}
}
