/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwintzer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 11:36:27 by jwintzer          #+#    #+#             */
/*   Updated: 2022/09/19 09:51:32 by jwintzer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
//#include <stdio.h>

char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strdup(char *src)
{
	char	*dst;
	int		i;

	i = 0;
	while (src[i])
		i++;
	dst = malloc(sizeof(int) * (i + 1));
	dst = ft_strcpy(dst, src);
	return (dst);
}

/*
int	main()
{
	char	a[9] = "test1234";
	char	*b;

	b = ft_strdup(a);
	printf("%s", b);
}
*/
