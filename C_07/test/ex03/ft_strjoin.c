/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwintzer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 10:22:42 by jwintzer          #+#    #+#             */
/*   Updated: 2022/09/21 13:32:40 by jwintzer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
#include <stdlib.h>

int	get_len(int size, char **strs, char *sep)
{
	int	i;
	int	j;
	int	len;

	i = 0;
	j = 0;
	len = 0;
	while (i < size)
	{
		j = 0;
		while (strs[i][j])
		{
			len++;
			j++;
		}
		j = 0;
		while (sep[j] && i < size - 1)
		{
			len++;
			j++;
		}
		i++;
	}
	return (len);
}

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
	dest[dest_size + i] = '\0';
	return (dest);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		i;
	char	*str;

	if (size == 0)
		return (malloc(0));
	str = malloc(sizeof(char) * (get_len(size, strs, sep) + 1));
	if (!str)
		return (0);
	*str = 0;
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
	printf("%s", ft_strjoin(4, a, "---"));
}
*/
