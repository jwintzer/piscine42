/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_string_tab.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwintzer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 17:43:42 by jwintzer          #+#    #+#             */
/*   Updated: 2022/09/19 17:50:18 by jwintzer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
//#include <stdio.h>

void	swap(char **str1_ptr, char **str2_ptr)
{
	char	*temp;

	temp = *str1_ptr;
	*str1_ptr = *str2_ptr;
	*str2_ptr = temp;
}

int	ft_strcmp(char *s1, char*s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}

void	ft_sort_string_tab(char **tab)
{
	int	i;
	int	stop;

	stop = 0;
	while (stop == 0 && tab[1])
	{
		stop = 1;
		i = 0;
		while (tab[i + 1])
		{
			if (ft_strcmp(tab[i], tab[i + 1]) > 0)
			{
				swap(&tab[i], &tab[i + 1]);
				stop = 0;
			}
			i++;
		}
	}
	i = 1;
}

/*
int	main(int argc, char **argv)
{
	(void)argc;
	ft_sort_string_tab(argv);
	for(int i = 0; i < 5; i++)
		printf("%s, ", argv[i]);
}
*/
