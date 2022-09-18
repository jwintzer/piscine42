/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwintzer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 13:59:30 by jwintzer          #+#    #+#             */
/*   Updated: 2022/09/12 08:51:04 by jwintzer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	recursive(int nb, int diviseur, int print)
{
	char	c;

	if (diviseur < 1)
		return ;
	c = nb / diviseur + '0';
	if (c != '0')
		print = 1;
	if (print == 1)
		write(1, &c, 1);
	recursive(nb % diviseur, diviseur / 10, print);
}

void	ft_putnbr(int nb)
{
	if (nb == 0)
	{
		write(1, "0", 1);
		return ;
	}
	if (nb == -2147483648)
	{
		write(1, "-2147483648", 11);
		return ;
	}
	if (nb < 0)
	{
		nb = -nb;
		write(1, "-", 1);
	}
	recursive(nb, 1000000000, 0);
}
