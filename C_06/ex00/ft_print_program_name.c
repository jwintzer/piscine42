/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_program_name.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwintzer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 10:01:41 by jwintzer          #+#    #+#             */
/*   Updated: 2022/09/08 10:11:27 by jwintzer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_program_name(char *program_name)
{
	int	i;

	i = 0;
	while (program_name[i])
	{
		write(1, &program_name[i], 1);
		i++;
	}
}

int	main(int argc, char **argv)
{
	argc++;
	argc--;
	ft_print_program_name(argv[0]);
}
