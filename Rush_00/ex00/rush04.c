/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush04.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwintzer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 11:05:07 by jwintzer          #+#    #+#             */
/*   Updated: 2022/09/03 13:57:08 by jwintzer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
void	ft_putchar(char c);

void	first_line(int x, int x2)
{
	while (x2 < x)
	{
		if (x2 == 0)
			ft_putchar('A');
		else if (x2 == x - 1)
			ft_putchar('C');
		else
			ft_putchar('B');
		x2++;
	}
}

void	middle_lines(int x, int x2)
{
	while (x2 < x)
	{
		if (x2 == 0 || x2 == x - 1)
			ft_putchar('B');
		else
			ft_putchar(' ');
		x2++;
	}
}

void	last_line(int x, int x2)
{
	while (x2 < x)
	{
		if (x2 == 0)
			ft_putchar('C');
		else if (x2 == x - 1)
			ft_putchar('A');
		else
			ft_putchar('B');
		x2++;
	}
}

void	rush(int x, int y)
{
	int	x2;
	int	y2;

	y2 = 0;
	while (y2 < y)
	{
		x2 = 0;
		if (y2 == 0)
			first_line(x, x2);
		else if (y2 == y - 1)
			last_line(x, x2);
		else
			middle_lines(x, x2);
		ft_putchar('\n');
		y2++;
	}
}
