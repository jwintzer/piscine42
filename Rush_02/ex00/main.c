/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwintzer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 08:01:20 by jwintzer          #+#    #+#             */
/*   Updated: 2022/09/18 22:08:02 by jwintzer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int		fill_dicts(char *str, char **left_dict, char **right_dict);
void	transformation(char *str, char **left_dict, char **right_dict, int max);
int		check_value(int argc, char **argv);
void	following(char *str2, char *str, int i);
int		checkdict(char *str);

int	get_line_number(char *str)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			count++;
		i++;
	}
	return (count + 1);
}

int	main(int argc, char **argv)
{
	char	str[1000];
	int		fd;
	int		i;

	if (!check_value(argc, argv))
		return (0);
	if (!(argc == 2 || argc == 3))
	{
		write(1, "Error\n", 6);
		return (0);
	}
	if (argc == 2)
	{
		fd = open("numbers.dict", O_RDONLY);
		i = read(fd, str, 998);
		following(argv[1], str, i);
		close(fd);
	}
	else
	{
		fd = open(argv[1], O_RDONLY);
		i = read(fd, str, 998);
		following(argv[2], str, i);
		close(fd);
	}
}

void	free_all(char **left_dict, char **right_dict, int line_number)
{
	while (line_number > 0)
	{
		free(left_dict[line_number]);
		free(right_dict[line_number]);
		line_number--;
	}
	free(left_dict);
	free(right_dict);
}

void	following(char *str2, char *str, int size)
{
	int		line_number;
	char	**dict[2];

	if (!checkdict(str))
	{
		write(1, "Error\n", 6);
		return ;
	}
	if (str[size - 1] == '\n')
		str[size] = '\0';
	else
	{
		str[size] = '\n';
		str[size + 1] = '\0';
	}
	line_number = get_line_number(str);
	dict[0] = (char **) malloc(sizeof(char *) * line_number);
	if (!dict[0])
		return ;
	dict[1] = (char **) malloc(sizeof(char *) * line_number);
	if (!dict[1])
		return ;
	fill_dicts(str, dict[0], dict[1]);
	transformation(str2, dict[0], dict[1], line_number - 1);
	free_all(dict[0], dict[1], line_number - 1);
}
