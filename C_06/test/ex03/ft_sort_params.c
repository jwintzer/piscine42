/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwintzer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 12:40:36 by jwintzer          #+#    #+#             */
/*   Updated: 2022/09/13 14:39:49 by jwintzer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_params(char *param)
{
	int	i;

	i = 0;
	while (param[i])
	{
		write(1, &param[i], 1);
		i++;
	}
}

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

int	main(int argc, char **argv)
{
	int	i;
	int	stop;

	stop = 0;
	while (stop == 0 && argv[1])
	{
		stop = 1;
		i = 1;
		while (argv[i + 1])
		{
			if (ft_strcmp(argv[i], argv[i + 1]) > 0)
			{
				swap(&argv[i], &argv[i + 1]);
				stop = 0;
			}
			i++;
		}
	}
	i = 1;
	while (i < argc)
	{
		ft_print_params(argv[i]);
		write(1, "\n", 1);
		i++;
	}
}
