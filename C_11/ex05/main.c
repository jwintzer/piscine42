/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwintzer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 16:58:39 by jwintzer          #+#    #+#             */
/*   Updated: 2022/09/22 16:25:24 by jwintzer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		ft_atoi(char *str);

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

int	check_error(char *operator, char *str)
{
	if (operator[0] == '/' && !operator[1] && str[0] == '0' && !str[1])
	{
		write(1, "Stop : division by zero\n", 24);
		return (1);
	}
	if (operator[0] == '%' && !operator[1] && str[0] == '0' && !str[1])
	{
		write(1, "Stop : modulo by zero\n", 22);
		return (1);
	}
	return (0);
}

int	main(int c, char **v)
{
	int		a;
	int		b;

	if (c != 4 || check_error(v[2], v[3]))
		return (0);
	a = ft_atoi(v[1]);
	b = ft_atoi(v[3]);
	if (v[2][0] == '+' && !v[2][1])
		ft_putnbr(a + b);
	else if (v[2][0] == '-' && !v[2][1])
		ft_putnbr(a - b);
	else if (v[2][0] == '/' && !v[2][1])
		ft_putnbr(a / b);
	else if (v[2][0] == '*' && !v[2][1])
		ft_putnbr(a * b);
	else if (v[2][0] == '%' && !v[2][1])
		ft_putnbr(a % b);
	else
		write(1, "0", 1);
	write(1, "\n", 1);
	return (0);
}
