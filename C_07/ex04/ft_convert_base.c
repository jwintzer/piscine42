/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwintzer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 11:52:59 by jwintzer          #+#    #+#             */
/*   Updated: 2022/09/15 14:59:57 by jwintzer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int	ft_atoi_base(char *str, char *base);

char	*rev_str(char *str)
{
	int		i;
	int		j;
	char	c;

	i = 0;
	j = 0;
	while (str[j])
		j++;
	j--;
	if (str[0] == '-')
		i = 1;
	while (i <= (j + 1) / 2)
	{
		c = str[i];
		str[i] = str[j];
		str[j] = c;
		i++;
		j--;
	}
	return (str);
}

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

char	*ft_putnbr_base(int nbr, char *base, int i, int size)
{
	int			base_size;
	long int	nbr2;
	char		*str;

	str = malloc(sizeof(char) * size);
	if (!test_base(base))
		return (0);
	base_size = 0;
	nbr2 = (long int) nbr;
	if (nbr2 < 0)
	{
		nbr2 *= -1;
		str[i] = '-';
		i++;
	}
	while (base[base_size])
		base_size++;
	while (nbr2 / base_size != 0)
	{
		str[i] = base[nbr2 % base_size];
		i++;
		nbr2 /= base_size;
	}
	str[i] = base[nbr2 % base_size];
	return (str);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	char	*str;
	int		value;
	int		i;
	int		diviseur;

	value = ft_atoi_base(nbr, base_from);
	if (!value)
		return (0);
	i = 0;
	diviseur = 1;
	while (value / diviseur != 0)
	{
		i++;
		diviseur *= 10;
	}
	str = ft_putnbr_base(value, base_to, 0, i);
	if (!str)
		return (0);
	str = rev_str(str);
	return (str);
}
/*
int main()
{
	char a[] = "     \n-+++---2345FD+ewq23FDdpuigefvFDF6349";
	char base_from[] = "0123456789ABCDEF";
	char base_to[] = "01";
	printf("%s", ft_convert_base(a, base_from, base_to));
}
*/
