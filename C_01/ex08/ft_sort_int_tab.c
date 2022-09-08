/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwintzer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 11:56:56 by jwintzer          #+#    #+#             */
/*   Updated: 2022/09/04 12:35:17 by jwintzer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_sort_int_tab(int *tab, int size)
{
	int	a;
	int	b;
	int	i;
	int	c;

	c = 1;
	while (c == 1)
	{
		c = 0;
		i = 0;
		while (i < size - 1)
		{
			a = tab[i];
			b = tab[i + 1];
			if (a > b)
			{
				tab [i] = b;
				tab [i + 1] = a;
				c = 1;
			}
			i++;
		}
	}	
}
