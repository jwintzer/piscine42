/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwintzer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 22:24:13 by jwintzer          #+#    #+#             */
/*   Updated: 2022/09/05 22:41:12 by jwintzer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcat(char *dest, char *src)
{
	int	i;
	int	dest_size;

	dest_size = 0;
	i = 0;
	while (dest[i] != '\0')
	{
		dest_size++;
		i++;
	}
	i = 0;
	while (src[i] != '\0')
	{
		dest[dest_size + i] = src[i];
		i++;
	}
	dest[dest_size + i] = '\0';
	return (dest);
}
