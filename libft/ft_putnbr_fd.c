/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmorgan- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 12:10:52 by pmorgan-          #+#    #+#             */
/*   Updated: 2018/11/23 15:49:29 by pmorgan-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Not sure whether this is appending the characters to the file or it's
** overwriting the previous character each time. To be checked in ft_putchar_fd.
*/

#include "libft.h"

static void	ft_putnbr_fd_recursive(int n, int fd)
{
	if (n < 0)
	{
		ft_putnbr_fd_recursive(n / 10, fd);
		ft_putchar_fd(((n % 10) * -1) + '0', fd);
	}
	return ;
}

void		ft_putnbr_fd(int n, int fd)
{
	if (n == 0)
		ft_putchar_fd('0', fd);
	else if (n < 0)
	{
		ft_putchar_fd('-', fd);
		ft_putnbr_fd_recursive(n, fd);
	}
	else
		ft_putnbr_fd_recursive(n * -1, fd);
	return ;
}
