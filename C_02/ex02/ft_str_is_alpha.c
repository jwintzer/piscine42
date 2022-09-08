/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_alpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwintzer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 10:43:08 by jwintzer          #+#    #+#             */
/*   Updated: 2022/09/05 19:03:35 by jwintzer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_str_is_alpha(char *str)
{
	int	i;
	int	i2;
	int	isok;

	i = 0;
	if (str[0] == '\0')
		return (1);
	while (str[i] != '\0')
	{
		i2 = 0;
		isok = 0;
		while (i2 < 26)
		{
			if (str[i] == 'A' + i2)
				isok = 1;
			if (str[i] == 'a' + i2)
				isok = 1;
			i2++;
		}
		if (isok == 0)
			return (0);
		i++;
	}
	return (1);
}
