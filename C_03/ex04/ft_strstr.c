/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwintzer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 22:44:36 by jwintzer          #+#    #+#             */
/*   Updated: 2022/09/06 14:44:54 by jwintzer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*following(int i, int i2, char *str, char *to_find)
{
	int	is_in_str;

	is_in_str = 0;
	if (to_find[0] == '\0')
		return (str);
	while (str[i])
	{
		i2 = 0;
		if (str[i] == to_find[0])
		{
			is_in_str = 1;
			while (to_find[i2])
			{
				if (str[i + i2] != to_find[i2])
					is_in_str = 0;
				i2++;
			}
			if (is_in_str == 1)
				return (&str[i]);
		}
		i++;
	}
	return (0);
}

char	*ft_strstr(char *str, char *to_find)
{
	int		i;
	int		i2;
	int		is_in_str;

	i = 0;
	i2 = 0;
	is_in_str = 0;
	str = following(i, i2, str, to_find);
	return (str);
}
