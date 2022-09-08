/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwintzer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 09:48:22 by jwintzer          #+#    #+#             */
/*   Updated: 2022/09/07 14:59:10 by jwintzer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

void	following(int nbr, char *base, int base_size);

void	ft_putnbr_base(int nbr, char *base)
{
	int	i;
	int	i2;

	i = 0;
	if (!(base[0] && base[1]))
		return ;
	while (base[i])
	{
		i2 = i + 1;
		if (base[i] == '+' || base[i] == '-')
			return ;
		if (base[i] < 32 || base[i] > 126)
			return ;
		while (base[i2])
		{
			if (base[i] == base[i2])
				return ;
			i2++;
		}
		i++;
	}
	following(nbr, base, i);
}

void	following(int nbr, char *base, int base_size)
{
	if (nbr < 0)
	{
		nbr = -nbr;
		write(1, "-", 1);
	}
	if (nbr / base_size == 0)
	{
		write(1, &base[nbr % base_size], 1);
		return ;
	}
	following(nbr / base_size, base, base_size);
	write(1, &base[nbr % base_size], 1);
}
