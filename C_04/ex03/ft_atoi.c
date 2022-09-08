/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwintzer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 14:09:46 by jwintzer          #+#    #+#             */
/*   Updated: 2022/09/07 10:30:42 by jwintzer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	str_to_int(char *str, int sign)
{
	int	i;
	int	value;

	i = 0;
	value = 0;
	while (str[i])
	{
		value *= 10;
		value += (str[i] - '0');
		i++;
	}
	if (sign % 2 == 1)
		return (-value);
	return (value);
}

int	following(char *str, int i, int i2, int sign)
{
	int		value;
	char	keep;

	value = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	while (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign++;
		i++;
	}
	if (str[i] != ' ' && str[i] != '+' && str[i] != '-')
		if (str[i] <= '0' && str[i] >= '9')
			return (0);
	while (str[i + i2] >= '0' && str[i + i2] <= '9')
		i2++;
	keep = str[i + i2];
	str[i + i2] = '\0';
	value = str_to_int(&str[i], sign);
	str[i + i2] = keep;
	return (value);
}

int	ft_atoi(char *str)
{
	int		i;
	int		i2;
	int		sign;
	int		value;

	i = 0;
	i2 = 0;
	sign = 0;
	value = 0;
	value = following(str, i, i2, sign);
	return (value);
}
