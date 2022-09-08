/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwintzer <jwintzer@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 12:32:54 by jwintzer          #+#    #+#             */
/*   Updated: 2022/09/02 08:15:37 by jwintzer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	call_write(a, b, c, d)
{
	if (c > a || (c == a && d > b))
	{	
		write(1, &a, 1);
		write(1, &b, 1);
		write(1, " ", 1);
		write(1, &c, 1);
		write(1, &d, 1);
		if (a != '9' || b != '8' || c != '9' || d != '9')
		{
			write(1, ",", 1);
			write(1, " ", 1);
		}
	}
}

void	following(a, b, c, d)
{
	while (a != '9' || b != '9')
	{
		c = '0';
		d = '0';
		while (c != '9' || d != '9')
		{
			if (d == '9')
			{
				c++;
				d = '0';
			}
			else
			{
				d++;
			}
			call_write(a, b, c, d);
		}	
		if (b == '9')
		{
			a++;
			b = '0';
		}
		else
			b++;
	}
}

void	ft_print_comb2(void)
{
	char	a;
	char	b;
	char	c;
	char	d;

	a = '0';
	b = '0';
	c = '0';
	d = '0';
	following (a, b, c, d);
}
