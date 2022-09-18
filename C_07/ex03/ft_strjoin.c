/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwintzer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 10:22:42 by jwintzer          #+#    #+#             */
/*   Updated: 2022/09/15 16:58:03 by jwintzer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

char	*ft_strcat(char *dest, char *src)
{
	int	i;
	int	dest_size;

	dest_size = 0;
	i = 0;
	while (dest[dest_size] != '\0')
		dest_size++;
	i = 0;
	while (src[i] != '\0')
	{
		dest[dest_size + i] = src[i];
		i++;
	}
	return (dest);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		i;
	char	*str;

	if (size == 0)
		return ("");
	str = malloc(sizeof(char *) * (2 * size - 1));
	if (!*strs)
		return (0);
	i = 0;
	while (i < size)
	{
		ft_strcat(str, strs[i]);
		if (i < size - 1)
			ft_strcat(str, sep);
		i++;
	}
	return (str);
}
/*
int	main()
{
	char	*a[4];
	a[0] = "ab";
	a[1] = "cd";
	a[2] = "ef";
	a[3] = "ghi";
	printf("%s", ft_strjoin(0, a, "---"));
}
*/
