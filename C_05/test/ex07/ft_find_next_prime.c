/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwintzer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 09:26:37 by jwintzer          #+#    #+#             */
/*   Updated: 2022/09/13 18:17:10 by jwintzer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
int	ft_find_next_prime(int nb)
{
	int	i;
	int	isok;

	if (nb < 2)
		return (2);
	while (1)
	{
		i = 2;
		isok = 1;
		while (i <= nb / i)
		{
			if (nb % i == 0)
			{
				nb++;
				isok = 0;
				break ;
			}
			i++;
		}
		if (isok == 1)
			return (nb);
	}
}
