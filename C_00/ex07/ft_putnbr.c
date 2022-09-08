/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwintzer <jwintzer@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 14:11:11 by jwintzer          #+#    #+#             */
/*   Updated: 2022/09/02 08:30:21 by jwintzer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	call_write(char *a, char sign, char z)
{
	unsigned char	i;
	unsigned char	j;

	j = 0;
	i = 0;
	if (sign == '-')
		write(1, &sign, 1);
	if (z == 'b')
		a[9] = '8';
	while (a[j] == '0')
		j ++;
	while (i < 10)
	{
		if (i >= j)
			write(1, &a[i], 1);
		i++;
	}
}

void	following(char sign, int nb, char z)

{
	char	a[10];

	a[0] = nb / 1000000000 + '0';
	a[1] = nb % 1000000000 / 100000000 + '0';
	a[2] = nb % 100000000 / 10000000 + '0';
	a[3] = nb % 10000000 / 1000000 + '0';
	a[4] = nb % 1000000 / 100000 + '0';
	a[5] = nb % 100000 / 10000 + '0';
	a[6] = nb % 10000 / 1000 + '0';
	a[7] = nb % 1000 / 100 + '0';
	a[8] = nb % 100 / 10 + '0';
	a[9] = nb % 10 + '0';
	call_write (a, sign, z);
}

void	ft_putnbr(int nb)
{
	char	sign;
	char	z;

	z = 'a';
	if (nb == -2147483648)
	{
		nb = -2147483640;
		z = 'b';
	}
	if (nb <= 0)
	{
		sign = '-';
		nb = nb - 2 * nb;
	}
	else
		sign = '0';
	following(sign, nb, z);
}
