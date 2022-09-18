/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_solution.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwintzer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 13:34:04 by jwintzer          #+#    #+#             */
/*   Updated: 2022/09/11 13:50:03 by jwintzer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	count(char i1, char i2, char i3, char i4)
{
	int	highest;
	int	count;

	highest = i1;
	count = 1;
	if (i2 > highest)
	{
		highest = i2;
		count++;
	}
	if (i3 > highest)
	{
		highest = i3;
		count++;
	}
	if (i4 > highest)
		count++;
	return (count + '0');
}

int	test_vertical(char *answer, char **tab)
{
	int		i;
	char	c;

	i = 0;
	while (i < 4)
	{
		c = count(answer[i], answer[i + 4], answer[i + 8], answer[i + 12]);
		if (tab[0][i] != c)
			return (0);
		i++;
	}
	i = 0;
	while (i < 4)
	{
		c = count(answer[i + 12], answer[i + 8], answer[i + 4], answer[i]);
		if (tab[1][i] != c)
			return (0);
		i++;
	}
	return (1);
}

int	test_horizontal(char *a, char **tab)
{
	int		i;
	char	c;

	i = 0;
	while (i < 4)
	{
		c = count(a[i * 4], a[1 + i * 4], a[2 + i * 4], a[3 + i * 4]);
		if (tab[2][i] != c)
			return (0);
		i++;
	}
	i = 0;
	while (i < 4)
	{
		c = count(a[3 + i * 4], a[2 + i * 4], a[1 + i * 4], a[i * 4]);
		if (tab[3][i] != c)
			return (0);
		i++;
	}
	return (1);
}

int	test_solution(char *answer, char **tab)
{
	if (test_vertical(answer, tab) && test_horizontal(answer, tab))
		return (1);
	return (0);
}
