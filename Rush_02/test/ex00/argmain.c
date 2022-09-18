/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argmain.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljerinec <ljerinec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 12:30:07 by ljerinec          #+#    #+#             */
/*   Updated: 2022/09/18 20:46:53 by jwintzer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

long long	ft_atoi(char *str)
{
	int			i;
	int			n;
	long long	nb;

	n = 1;
	nb = 0;
	i = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\v'
		|| str[i] == '\f' || str[i] == '\r' || str[i] == '\n')
		i++;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
		n *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		nb = nb * 10 + (str[i] - '0');
		i++;
	}
	return (n * nb);
}

int	ft_str_is_numeric(char	*str)
{
	int	i;
	int	rt;

	rt = 1;
	i = 0;
	while (str[i])
	{
		if (rt != 0)
		{
			if ((str[i] <= '9') && (str[i] >= '0'))
				rt = 1;
			else
				rt = 0;
		}
		i++;
	}
	return (rt);
}

int	check_value(int argc, char **argv)
{
	char		*input;
	long long	number;

	if (argc == 2)
		input = argv[1];
	else if (argc == 3)
		input = argv[2];
	else
	{
		write(1, "Error\n", 6);
		return (0);
	}
	number = ft_atoi(input);
	if (number > 4294967295 || number < 0)
	{
		write(1, "Error\n", 6);
		return (0);
	}
	return (1);
}
