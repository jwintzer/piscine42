/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fibonacci.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwintzer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 15:37:26 by jwintzer          #+#    #+#             */
/*   Updated: 2022/09/08 17:49:02 by jwintzer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	recursive(int index, int nbr1, int nbr2, int nbr3)
{
	if (index == 0)
		return (nbr1);
	nbr3 = nbr1 + nbr2;
	index--;
	return (recursive(index, nbr2, nbr3, nbr1));
}

int	ft_fibonacci(int index)
{
	int	nbr1;
	int	nbr2;
	int	nbr3;

	nbr1 = 0;
	nbr2 = 1;
	nbr3 = 1;
	if (index < 0)
		return (-1);
	return (recursive(index, nbr1, nbr2, nbr3));
}
