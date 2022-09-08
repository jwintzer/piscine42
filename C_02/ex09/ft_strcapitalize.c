/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwintzer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 14:33:31 by jwintzer          #+#    #+#             */
/*   Updated: 2022/09/05 21:18:03 by jwintzer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	is_it_lower(char c)
{
	int	i;

	i = 0;
	while (i < 26)
	{
		if (c == 'a' + i)
			return (1);
		i++;
	}
	return (0);
}

int	is_it_upper(char c)
{
	int	i;

	i = 0;
	while (i < 26)
	{
		if (c == 'A' + i)
			return (1);
		i++;
	}
	return (0);
}

int	is_it_digit(char c)
{
	int	i;

	i = 0;
	while (i < 10)
	{
		if (c == '0' + i)
			return (1);
		i++;
	}
	return (0);
}

char	*get_lines(char *str, int i, int new_word)
{
	int	is_lower;
	int	is_upper;
	int	is_digit;

	while (str[i] != '\0')
	{
		is_lower = is_it_lower(str[i]);
		is_upper = is_it_upper(str[i]);
		is_digit = is_it_digit(str[i]);
		if (is_lower == 0 && is_upper == 0 && is_digit == 0)
			new_word = 1;
		if (is_lower == 1 || is_upper == 1 || is_digit == 1)
		{
			if (is_lower == 1 && new_word == 1)
				str[i] = str[i] - 32;
			if (is_upper == 1 && new_word == 0)
				str[i] = str[i] + 32;
			new_word = 0;
		}
		is_lower = 0;
		i++;
	}
	return (str);
}

char	*ft_strcapitalize(char *str)
{
	int	i;
	int	new_word;

	i = 0;
	new_word = 1;
	str = get_lines(str, i, new_word);
	return (str);
}
