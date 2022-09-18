/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transformation_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwintzer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 21:02:55 by jwintzer          #+#    #+#             */
/*   Updated: 2022/09/18 21:04:12 by jwintzer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	units(char c, char **left_dict, char **right_dict, int max)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < max)
	{
		if (left_dict[i][0] == c && !left_dict[i][1])
		{
			while (right_dict[i][j])
				j++;
			write(1, right_dict[i], j);
		}
		i++;
	}
}

void	elevens(char c, char **left_dict, char **right_dict, int max)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < max)
	{
		if (left_dict[i][0] == '1' && left_dict[i][1] == c && !left_dict[i][2])
		{
			while (right_dict[i][j])
				j++;
			write(1, right_dict[i], j);
		}
		i++;
	}
}

void	tens(char *str, char **left_dict, char **right_dict, int max)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (str[0] != '1')
	{
		while (i < max)
		{
			if (left_dict[i][0] == str[0] && left_dict[i][1] == '0'
					&& !left_dict[i][2])
			{
				while (right_dict[i][j])
					j++;
				write(1, right_dict[i], j);
			}
			i++;
		}
	}
	else
		elevens(str[1], left_dict, right_dict, max);
}

void	hundreds(char c, char **left_dict, char **right_dict, int max)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	units(c, left_dict, right_dict, max);
	while (i < max)
	{
		if (left_dict[i][0] == '1' && left_dict[i][1] == '0'
				&& left_dict[i][2] == '0' && !left_dict[i][3])
		{
			while (right_dict[i][j])
				j++;
			write(1, " ", 1);
			write(1, right_dict[i], j);
		}
		i++;
	}
}
