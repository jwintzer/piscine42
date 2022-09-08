/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwintzer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 14:05:01 by jwintzer          #+#    #+#             */
/*   Updated: 2022/09/04 12:09:32 by jwintzer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_rev_int_tab(int *tab, int size)
{
	int	a;
	int	b;
	int	i;

	i = 0;
	while (i < size / 2)
	{
		a = tab[size - i - 1];
		b = tab[i];
		tab[size - i - 1] = b;
		tab[i] = a;
		i++;
	}
}
