/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwintzer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 14:55:09 by jwintzer          #+#    #+#             */
/*   Updated: 2022/09/08 09:50:10 by jwintzer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	tri(char *str, char *base);
int	following(char *str, char *base, int sign);
int	following2(char *str, char *base, int sign, int i4);
int	base_to_decimal(char *str, char *base, int i, int i2);

int	ft_atoi_base(char *str, char *base)
{
	int	i;
	int	i2;

	i = 0;
	if (!(base[0] && base[1]))
		return (0);
	while (base[i])
	{
		i2 = i + 1;
		if (base[i] == '+' || base[i] == '-')
			return (0);
		if (base[i] < 32 || base[i] > 126)
			return (0);
		while (base[i2])
		{
			if (base[i] == base[i2])
				return (0);
			i2++;
		}
		i++;
	}
	return (tri(str, base));
}

int	tri(char *str, char *base)
{
	int		i;
	int		value;
	int		sign;

	i = 0;
	value = 0;
	sign = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	while (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign++;
		i++;
	}
	return (following(&str[i], base, sign));
}

int	following(char *str, char *base, int sign)
{
	int		i;
	int		i2;
	int		stop;
	int		value;

	i = 0;
	i2 = 0;
	stop = 0;
	while (str[i] && stop == 0)
	{
		stop = 1;
		i2 = 0;
		while (base[i2])
		{
			if (str[i] == base[i2])
				stop = 0;
			i2++;
		}
		i++;
	}
	if (stop == 1)
		i--;
	value = (following2(str, base, sign, i));
	return (value);
}

int	following2(char *str, char *base, int sign, int i4)
{
	int		i;
	int		i2;
	int		i3;
	int		value;
	char	keep;

	keep = str[i4];
	str[i4] = '\0';
	i = 0;
	i2 = 1;
	i3 = 0;
	value = 0;
	while (base[i3])
		i3++;
	while (str[i + 1])
	{
		i++;
		i2 *= i3;
	}
	i = 0;
	value = (base_to_decimal(str, base, i, i2));
	str[i4] = keep;
	if (sign % 2 == 1)
		return (-value);
	return (value);
}

int	base_to_decimal(char *str, char *base, int i, int i2)
{
	int	i3;
	int	i4;
	int	value;

	i3 = 0;
	i4 = 0;
	value = 0;
	if (!(str[i]))
		return (0);
	while (base[i3])
		i3++;
	while (base[i4] && base[i4] != str[i])
		i4++;
	i++;
	i2 /= i3;
	if (!(str[i]))
		value += i4;
	value += base_to_decimal(str, base, i, i2) +(i4 * i3 * i2);
	return (value);
}
