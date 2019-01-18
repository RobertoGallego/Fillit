/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmorgan- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 16:25:07 by pmorgan-          #+#    #+#             */
/*   Updated: 2018/11/23 15:30:53 by pmorgan-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_putnbr_recursive(int n)
{
	if (n < 0)
	{
		ft_putnbr_recursive(n / 10);
		ft_putchar(((n % 10) * -1) + '0');
	}
	return ;
}

void		ft_putnbr(int n)
{
	if (n == 0)
		ft_putchar('0');
	else if (n < 0)
	{
		ft_putchar('-');
		ft_putnbr_recursive(n);
	}
	else
		ft_putnbr_recursive(n * -1);
	return ;
}
