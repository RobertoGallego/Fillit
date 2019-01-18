/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr_range.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmorgan- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/07 17:12:02 by pmorgan-          #+#    #+#             */
/*   Updated: 2019/01/07 17:13:30 by pmorgan-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strchr_range(const char *s, char low_bound, char up_bound)
{
	while (*s)
	{
		if (*s >= low_bound && *s <= up_bound)
			return ((char*)s);
		s++;
	}
	if (*s >= low_bound && *s <= up_bound)
		return ((char*)s);
	return (0);
}
