/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwintzer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 09:48:22 by jwintzer          #+#    #+#             */
/*   Updated: 2022/09/14 10:15:16 by jwintzer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int	test_base(char *base)
{
	int	i;
	int	i2;

	i = 0;
	while (base[i])
	{
		if (base[i] == '+' || base[i] == '-')
			return (0);
		if (base[i] < 32 || base[i] > 126)
			return (0);
		i2 = i + 1;
		while (base[i2])
		{
			if (base[i] == base[i2])
				return (0);
			i2++;
		}
		i++;
	}
	if (i < 2)
		return (0);
	return (1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int			base_size;
	long int	nbr2;

	if (!test_base(base))
		return ;
	base_size = 0;
	nbr2 = (long int) nbr;
	if (nbr2 < 0)
	{
		nbr2 *= -1;
		write(1, "-", 1);
	}
	while (base[base_size])
		base_size++;
	if (nbr2 / base_size == 0)
	{
		write(1, &base[nbr2 % base_size], 1);
		return ;
	}
	ft_putnbr_base(nbr2 / base_size, base);
	write(1, &base[nbr2 % base_size], 1);
}
