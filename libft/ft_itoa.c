/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmorgan- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/17 17:25:17 by pmorgan-          #+#    #+#             */
/*   Updated: 2018/12/03 14:51:55 by pmorgan-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	check_negative(size_t *n_len, _Bool *n_neg, int n)
{
	*n_len = 0;
	*n_neg = (n < 0) ? 1 : 0;
	(n < 0) ? (*n_len)++ : 0;
}

static void	count_digits(int n, size_t *n_len_ptr)
{
	while (n != 0)
	{
		n /= 10;
		(*n_len_ptr)++;
	}
}

char		*ft_itoa(int n)
{
	size_t	n_len;
	_Bool	n_neg;
	char	*str;
	int		i;

	if (n == 0)
	{
		if (!(str = ft_strnew(1)))
			return ("0");
		*str = '0';
		return (str);
	}
	check_negative(&n_len, &n_neg, n);
	count_digits(n, &n_len);
	if (!(str = ft_strnew(n_len)))
		return (NULL);
	i = 0;
	while (n != 0)
	{
		str[i++] = '0' + ((n_neg) ? (n % 10) * -1 : n % 10);
		n /= 10;
	}
	if (n_neg)
		str[i] = '-';
	return (ft_strrev(str));
}
