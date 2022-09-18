/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwintzer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 10:59:56 by jwintzer          #+#    #+#             */
/*   Updated: 2022/09/13 12:55:28 by jwintzer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_answer(int *answer)
{
	int		i;
	char	c;

	i = 0;
	while (i < 10)
	{
		c = answer[i] + '0';
		write(1, &c, 1);
		i++;
	}
	write(1, "\n", 1);
}

int	test_value(int *answer, int x, int y)
{
	int	i;

	i = x - 1;
	while (i >= 0)
	{
		if (answer[i] == y)
			return (0);
		if (answer[i] == y + x - i || answer[i] == y - x + i)
			return (0);
		i--;
	}
	return (1);
}

int	recursive(int *answer, int x, int y, int *count)
{
	if (x == 10)
	{
		print_answer(answer);
		*count = *count + 1;
		return (0);
	}
	while (y < 10)
	{
		if (test_value(answer, x, y))
		{
			answer[x] = y;
			recursive(answer, x + 1, 0, count);
		}
		y++;
	}
	return (0);
}

int	ft_ten_queens_puzzle(void)
{
	int	answer[10];
	int	i;
	int	count;

	i = 0;
	while (i < 10)
	{
		answer[i] = -1;
		i++;
	}
	recursive(answer, 0, 0, &count);
	return (count);
}
