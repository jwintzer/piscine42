/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwintzer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 16:58:53 by jwintzer          #+#    #+#             */
/*   Updated: 2022/09/19 16:59:05 by jwintzer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	str_to_int(char *str, int sign)
{
	int	i;
	int	value;

	i = 0;
	value = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		value *= 10;
		value += (str[i] - '0');
		i++;
	}
	if (sign % 2 == 1)
		return (-value);
	return (value);
}

int	following(char *str, int i, int sign)
{
	int		value;

	value = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	while (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign++;
		i++;
	}
	value = str_to_int(&str[i], sign);
	return (value);
}

int	ft_atoi(char *str)
{
	int		i;
	int		sign;
	int		value;

	i = 0;
	sign = 0;
	value = 0;
	value = following(str, i, sign);
	return (value);
}
