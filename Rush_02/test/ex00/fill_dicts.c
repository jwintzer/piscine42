/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_dicts.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwintzer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 08:08:39 by jwintzer          #+#    #+#             */
/*   Updated: 2022/09/18 21:43:51 by jwintzer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	economie_le_rat(char *str, int i)
{
	while (str[i] >= '0' && str[i] <= '9')
		i++;
	while (str[i] == ':' || str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	return (i);
}

int	fill_right_dict(char *str, char **right_dict, int i, int k)
{
	int	j;

	while (str[i])
	{
		j = 0;
		i = economie_le_rat(str, i);
		while (str[i + j] != '\n')
			j++;
		right_dict[k] = (char *) malloc(sizeof(char) * (j + 1));
		if (!right_dict)
			return (0);
		j = 0;
		while (str[i] != '\n' && str[i])
		{
			right_dict[k][j] = str[i];
			i++;
			j++;
		}
		right_dict[k][j] = '\0';
		i++;
		k++;
	}
	right_dict[k] = 0;
	return (1);
}

int	fill_left_dict(char *str, char **left_dict, int i, int k)
{
	int	j;

	while (str[i])
	{
		j = 0;
		while (str[i + j] >= '0' && str[i + j] <= '9')
			j++;
		left_dict[k] = (char *) malloc(sizeof(char) * (j + 1));
		if (!left_dict)
			return (0);
		j = 0;
		while (str[i] >= '0' && str[i] <= '9')
		{
			left_dict[k][j] = str[i];
			i++;
			j++;
		}
		left_dict[k][j] = '\0';
		while (str[i] != '\n' && str[i])
			i++;
		i++;
		k++;
	}
	left_dict[k] = 0;
	return (1);
}

int	fill_dicts(char *str, char **left_dict, char **right_dict)
{
	fill_left_dict(str, left_dict, 0, 0);
	fill_right_dict(str, right_dict, 0, 0);
	return (1);
}
