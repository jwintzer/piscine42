/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transformation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwintzer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 12:34:32 by jwintzer          #+#    #+#             */
/*   Updated: 2022/09/18 21:51:54 by jwintzer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

void	units(char c, char **left_dict, char **right_dict, int max);
void	elevens(char c, char **left_dict, char **right_dict, int max);
void	tens(char *str, char **left_dict, char **right_dict, int max);
void	hundreds(char c, char **left_dict, char **right_dict, int max);

void	billions(int size, char **left_dict, char **right_dict, int max)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (size == 10)
	{
		while (i < max)
		{
			if (left_dict[i][0] == '1' && left_dict[i][1] == '0'
					&& left_dict[i][2] == '0' && left_dict[i][3] == '0'
					&& left_dict[i][4] == '0' && left_dict[i][5] == '0'
					&& left_dict[i][6] == '0' && left_dict[i][7] == '0'
					&& left_dict[i][8] == '0' && left_dict[i][9] == '0'
					&& !left_dict[i][10])
			{
				while (right_dict[i][j])
					j++;
				write(1, right_dict[i], j);
			}
			i++;
		}
	}
}

void	millions(int size, char **left_dict, char **right_dict, int max)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (size == 7)
	{
		while (i < max)
		{
			if (left_dict[i][0] == '1' && left_dict[i][1] == '0'
					&& left_dict[i][2] == '0' && left_dict[i][3] == '0'
					&& left_dict[i][4] == '0' && left_dict[i][5] == '0'
					&& left_dict[i][6] == '0' && !left_dict[i][7])
			{
				while (right_dict[i][j])
					j++;
				write(1, right_dict[i], j);
			}
			i++;
		}
	}
	else
		billions(size, left_dict, right_dict, max);
}

void	thousands(int size, char **left_dict, char **right_dict, int max)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	write(1, " ", 1);
	if (size == 4)
	{
		while (i < max)
		{
			if (left_dict[i][0] == '1' && left_dict[i][1] == '0'
					&& left_dict[i][2] == '0' && left_dict[i][3] == '0'
					&& !left_dict[i][4])
			{
				while (right_dict[i][j])
					j++;
				write(1, right_dict[i], j);
			}
			i++;
		}
	}
	else
		millions(size, left_dict, right_dict, max);
}

void	transformation(char *str, char **left_dict, char **right_dict, int max)
{
	int	i;
	int	size;

	i = 0;
	size = 0;
	while (str[size])
		size++;
	while (str[i])
	{
		if (size % 3 == 1 && (str[i] != '0' || (size == 1 && i == 0)))
			if (str[i - 1] != '1')
				units(str[i], left_dict, right_dict, max);
		if (size % 3 == 2 && str[i] != '0')
			tens(&str[i], left_dict, right_dict, max);
		if (size % 3 == 0 && str[i] != '0')
			hundreds(str[i], left_dict, right_dict, max);
		if (size % 3 == 1 && size != 1)
			if (!(str[i] == '0' && str[i - 1] == '0'
					&& str[i - 2] == '0' && i < 2))
				thousands(size, left_dict, right_dict, max);
		i++;
		size--;
		if (size > 0 && str[i] != '0')
			write(1, " ", 1);
	}
}
