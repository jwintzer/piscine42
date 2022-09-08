/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strupcase.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwintzer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 13:45:36 by jwintzer          #+#    #+#             */
/*   Updated: 2022/09/05 14:30:18 by jwintzer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char	*ft_strupcase(char *str)
{
	int	i;
	int	i2;
	int	is_lower;

	i = 0;
	while (str[i] != '\0')
	{
		i2 = 0;
		is_lower = 0;
		while (i2 < 26)
		{
			if (str[i] == 'a' + i2)
				is_lower = 1;
			i2++;
		}
		if (is_lower == 1)
			str[i] = str[i] + -32;
		i++;
	}
	return (str);
}
