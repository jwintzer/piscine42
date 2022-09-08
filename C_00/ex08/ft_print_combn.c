/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwintzer <jwintzer@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 18:31:36 by jwintzer          #+#    #+#             */
/*   Updated: 2022/09/01 19:37:55 by jwintzer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	des_boucles(char a, char b, char c, char d)
{
	while (a <= '1')
	{
		b = a + '1';
		while (b <= '2')
		{
			c = b + 1;
			while (c <= '3')
			{
				d = c + 1;
				while (d <= '4')
				{
					e = d + 1;
					while (e <= '5')
					{
						e++;
					}			
					d++;
				}
				c++;
			}
			b++;
		}
		a++;
	}
}

void	variables(void)
{
	char	a;

	a = '0';
	des_boucles(a, '0', '0', '0', '0', '0', '0', '0', '0');
}
