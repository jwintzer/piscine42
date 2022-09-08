/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwintzer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 10:56:36 by jwintzer          #+#    #+#             */
/*   Updated: 2022/09/06 12:10:12 by jwintzer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	dest_size;
	unsigned int	src_size;

	i = 0;
	dest_size = 0;
	src_size = 0;
	while (dest[dest_size])
		dest_size++;
	while (src[src_size])
		src_size++;
	while (src[i] && (dest_size + i) < size -1 && size > 0)
	{
		dest[dest_size + i] = src[i];
		i++;
	}
	dest[dest_size + i] = '\0';
	if (dest_size < size)
		return (dest_size + src_size);
	else
		return (src_size + size);
}
