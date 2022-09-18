/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_solution.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwintzer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 13:55:51 by jwintzer          #+#    #+#             */
/*   Updated: 2022/09/11 15:37:19 by jwintzer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	test_solution(char *answer, char **tab);
int	test_value(char *answer, int index, int value);

void	print_answer(char *answer)
{
	int	i;

	i = 0;
	while (i < 16)
	{
		write(1, &answer[i], 1);
		if (i % 4 != 3)
			write(1, " ", 1);
		if (i % 4 == 3)
			write(1, "\n", 1);
		i++;
	}
}

int	find_solution(char *answer, char **tab, int i)
{
	int	i2;

	if (i == 16 && test_solution(answer, tab))
	{
		print_answer(answer);
		return (1);
	}
	if (i < 16)
	{
		i2 = 1;
		while (i2 <= 5)
		{
			if (test_value(answer, i, i2))
			{
				answer[i] = i2 + '0';
				if (find_solution(answer, tab, i + 1))
					return (1);
			}
			else
				answer[i] = '0';
			i2++;
		}
	}
	return (0);
}
