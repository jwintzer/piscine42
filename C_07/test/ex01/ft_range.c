/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwintzer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 12:37:26 by jwintzer          #+#    #+#             */
/*   Updated: 2022/09/19 09:53:15 by jwintzer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	*tab;
	int	i;

	if (min >= max)
		return (0);
	i = 0;
	tab = malloc(sizeof(int) * (max - min));
	while (i < (max - min))
	{
		tab[i] = min + i;
		i++;
	}
	return (tab);
}
