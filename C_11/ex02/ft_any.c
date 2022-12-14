/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_any.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwintzer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 16:18:10 by jwintzer          #+#    #+#             */
/*   Updated: 2022/09/19 16:28:43 by jwintzer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_any(char **tab, int (*f)(char*))
{
	int	i;
	int	isok;

	i = 0;
	isok = 0;
	while (tab[i] != 0)
	{
		if (f(tab[i]) != 0)
			isok = 1;
		i++;
	}
	return (isok);
}
