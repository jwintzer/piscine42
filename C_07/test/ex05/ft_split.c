/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwintzer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 14:44:48 by jwintzer          #+#    #+#             */
/*   Updated: 2022/09/21 14:34:37 by jwintzer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
//#include <stdio.h>

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
	word = malloc(sizeof(char) * (i2 + 1));
	while (find_chars(str[*pos], charset))
		*pos = *pos + 1;
	i = 0;
	while (!find_chars(str[*pos], charset) && str[*pos])
	{
		word[i] = str[*pos];
		i++;
		*pos = *pos + 1;
	}
	word[i] = '\0';
	return (word);
}

char	**ft_split(char *str, char *charset)
{
	char	**strs;
	int		i;
	int		pos;
	int		word_number;

	word_number = get_word_number(str, charset);
	strs = malloc(sizeof(char *) * (word_number));
	i = 0;
	pos = 0;
	while (i < word_number - 1)
	{
		strs[i] = get_word(str, charset, &pos);
		i++;
	}
	strs[i] = 0;
	return (strs);
}
/*
int	main(int argc, char **argv)
{
	(void)argc;
	for(int i = 0; i < get_word_number(argv[1], argv[2]); i++)
		printf("%s\n", ft_split(argv[1], argv[2])[i]);
}
*/
