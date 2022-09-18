/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkdict.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljerinec <ljerinec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 19:39:02 by ljerinec          #+#    #+#             */
/*   Updated: 2022/09/18 22:08:52 by jwintzer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	checkdict(char *str)
{
	int	i;
	int	apres_double_point;
	int	boolean;

	boolean = 0;
	apres_double_point = 0;
	i = 0;
	while (str[i])
	{
		while (apres_double_point == 0)
		{
			if (str[i] == ':')
				apres_double_point = 1;
			if (str[i] >= 'a' && str[i] <= 'z')
				return (0);
			i++;
		}
		while (apres_double_point == 1)
		{
			if (str[i] == '\n' || !str[i])
				apres_double_point = 0;
			i++;
		}
	}
	return (1);
}
