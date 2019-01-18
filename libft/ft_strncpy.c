/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmorgan- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/06 22:08:56 by pmorgan-          #+#    #+#             */
/*   Updated: 2018/08/14 11:48:43 by pmorgan-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int src_len;
	unsigned int cpy_i;

	src_len = 0;
	cpy_i = 0;
	while (src[src_len])
		++src_len;
	while (cpy_i < n && cpy_i < src_len)
	{
		dest[cpy_i] = src[cpy_i];
		++cpy_i;
	}
	while (cpy_i < n)
	{
		dest[cpy_i] = '\0';
		++cpy_i;
	}
	return (dest);
}
