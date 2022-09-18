/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwintzer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 10:49:19 by jwintzer          #+#    #+#             */
/*   Updated: 2022/09/11 17:11:18 by jwintzer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

int	test_value(char *answer, int index, int value);
int	test_solution(char *answer, char **tab);
int	find_solution(char *answer, char **tab, int i);

void	free_memory(char *answer, char **tab)
{
	free(answer);
	free(tab[0]);
	free(tab[1]);
	free(tab[2]);
	free(tab[3]);
}

int	filter_str(char *str, char **tab)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (i % 2 == 0)
		{
			if (i < 7 && str[i] > '0' && str[i] < '5')
				tab[0][i / 2] = str[i];
			else if (i < 15 && str[i] > '0' && str[i] < '5')
				tab[1][(i - 8) / 2] = str[i];
			else if (i < 23 && str[i] > '0' && str[i] < '5')
				tab[2][(i - 16) / 2] = str[i];
			else if (i < 31 && str[i] > '0' && str[i] < '5')
				tab[3][(i - 24) / 2] = str[i];
			else
				return (0);
		}
		if (i % 2 == 1)
			if (str[i] != ' ' || i > 30)
				return (0);
		i++;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	char	*answer;
	char	*tab[4];
	int		i;

	answer = (char *) malloc(sizeof(char) * 16);
	tab[0] = (char *) malloc(sizeof(char) * 4);
	tab[1] = (char *) malloc(sizeof(char) * 4);
	tab[2] = (char *) malloc(sizeof(char) * 4);
	tab[3] = (char *) malloc(sizeof(char) * 4);
	i = 0;
	while (i < 16)
	{
		answer[i] = '0';
		i++;
	}
	answer[16] = '\0';
	if (argc != 2)
	{
		write(1, "Error\n", 6);
		return (0);
	}
	if (!filter_str(argv[1], tab) || !find_solution(answer, tab, 0))
		write(1, "Error\n", 6);
	free_memory(answer, tab);
	return (0);
}
