/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwintzer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 17:49:33 by jwintzer          #+#    #+#             */
/*   Updated: 2022/09/08 18:52:47 by jwintzer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	recursive(int nb, int i, int i2)
{
	if (i == i2)
		return (i);
	if ((nb % i + i) % 2 != 0)
		return (0);
	i2 = i;
	return (recursive(nb, (nb / i + i) / 2, i2));
}

int ft_sqrt(int nb)
{
	if (nb == 2)
		return (0);
	if (nb == 1)
		return (1);
	return (recursive(nb, nb / 2, 1));
}
