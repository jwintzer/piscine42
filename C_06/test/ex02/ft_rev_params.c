/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_params.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwintzer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 12:36:09 by jwintzer          #+#    #+#             */
/*   Updated: 2022/09/08 12:38:55 by jwintzer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_rev_params(char *param)
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
	while (argc > 1)
	{
		ft_rev_params(argv[argc - 1]);
		argc--;
		write(1, "\n", 1);
	}
}
