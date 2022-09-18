/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwintzer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 14:44:48 by jwintzer          #+#    #+#             */
/*   Updated: 2022/09/15 14:46:40 by jwintzer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	find_chars(char c, char *charset)
{
	int	i;

	i = 0;
	while (charset[i])
	{
		if (c == charset[i])
			return (1);
		i++;
	}
	return (0);
}

int	get_word_number(char *str, char *charset)
{
	int	i;
	int	word_count;

	i = 0;
	word_count = 0;
	while (str[i])
	{
		while (find_chars(str[i], charset) && str[i])
			i++;
		if (!find_chars(str[i], charset) && str[i])
			word_count++;
		while (!find_chars(str[i], charset) && str[i])
			i++;
	}
	return (word_count + 1);
}

char	*get_word(char *str, char *charset, int *pos)
{
	int		i;
	int		i2;
	char	*word;

	i = *pos;
	i2 = 0;
	while (find_chars(str[i], charset) && str[i])
		i++;
	while (!find_chars(str[i], charset) && str[i])
	{
		i++;
		i2++;
	}
	word = malloc(sizeof(char) * i2);
	while (find_chars(str[*pos], charset))
		*pos = *pos + 1;
	i = 0;
	while (!find_chars(str[*pos], charset))
	{
		word[i] = str[*pos];
		i++;
		*pos = *pos + 1;
	}
	return (word);
}

char	**ft_split(char *str, char *charset)
{
	char	**strs;
	int		i;
	int		pos;
	int		word_number;

	word_number = get_word_number(str, charset);
	strs = malloc(sizeof(char *) * word_number);
	i = 0;
	pos = 0;
	while (i < word_number)
	{
		strs[i] = get_word(str, charset, &pos);
		i++;
	}
	strs[i] = 0;
	return (strs);
}

/*
int	main()
{
	char	*a = "salut comment ca";
	char	*b = "a";
	ft_split(a, b);
}
*/
