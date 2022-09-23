/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwintzer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 13:09:48 by jwintzer          #+#    #+#             */
/*   Updated: 2022/09/21 10:03:18 by jwintzer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	i;

	i = 0;
	if (min >= max)
	{
		*range = malloc(sizeof(int));
		*range = NULL;
		return (0);
	}
	*range = (int *) malloc(sizeof(int) * (max - min));
	if (!*range)
		return (0);
	while (i < max - min)
	{
		(*range)[i] = min + i;
		i++;
	}
	return (max - min);
}
int	main()
{
	int	a = -3;
	int	b = 4;
	int	*tab;
	printf("%d, ", ft_ultimate_range(&tab, a, b));
	for (int i = 0; i < 10; i++)
		printf("%d", tab[i]);
}
