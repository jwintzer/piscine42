/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwintzer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 12:40:36 by jwintzer          #+#    #+#             */
/*   Updated: 2022/09/08 13:15:56 by jwintzer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_sort(int argc, char **argv);
int	ft_strcmp(char *s1, char*s2);

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

int	main(int argc, char **argv)
{
	int i;

	i = 0;
	ft_sort(argc, argv);
	while (i < argc)
	{
		ft_print_params(argv[i]);
		i++;
		write(1, "\n", 1);
	}
}

int	ft_strcmp(char *s1, char*s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}

void	ft_sort(int argc, char **argv)
{
	int		i;
	int		stop;
	char	*a;

	i = argc;
	stop = 0;
	while (stop == 0)
	{
		stop = 1;
		while (i > 1)
		{
			a = argv[i];
			if (ft_strcmp(argv[i], argv[i + 1]) < 0)
			{
				argv[i] = argv[i + 1];
				argv[i + 1] = a;
				stop = 0;
			}
			i--;
		}
	}
}
