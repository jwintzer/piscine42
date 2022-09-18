/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_value.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwintzer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 13:51:29 by jwintzer          #+#    #+#             */
/*   Updated: 2022/09/13 10:30:25 by jwintzer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	test_value2(char *answer, int index, int value)
{
	int	i;

	i = index;
	while ((i + 1) % 4 > 0) // droite
	{
		if (answer[i + 1] == value + '0')
			return (0);
		i++;
	}
	i = index;
	while ((i - 1) % 4 < 3 && i != 0) //gauche
	{
		if (answer[i - 1] == value + '0')
			return (0);
		i--;
	}
	return (1);
}

int	test_value(char *answer, int index, int value)
{
	int	i;

	i = index;
	if (value == 5)
		return (0);
	while (i - 4 >= 0)
	{
		if (answer[i - 4] == value + '0') //haut
			return (0);
		i -= 4;
	}
	i = index;
	while (i + 4 < 16)
	{
		if (answer[i + 4] == value + '0') //bas
			return (0);
		i += 4;
	}
	return (test_value2(answer, index, value));
}
