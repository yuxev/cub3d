/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chyata.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aasselma <aasselma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 13:20:37 by aziyani           #+#    #+#             */
/*   Updated: 2023/11/20 01:50:42 by aasselma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../CUB3D.h"

int	ft_count(char	*s1)
{
	int	count;
	int	i;

	i = 0;
	count = 0;
	while (s1[i])
	{
		if (s1[i] == ',')
			count++;
		i++;
	}
	return (count);
}

// int	valid_line(char *line)
// {
// 	int	i;

// 	i = 0;
// 	while (line[i])
// 	{
// 		if (line[i] == '1')
// 			return (1);
// 		i++;
// 	}
// 	return (0);
// }

int	is_valid_line(char *line)
{
	int	i;
	int	v;

	i = 0;
	v = 0;
	while (line[i])
	{
		if (!(line[i] == '\n' || line[i] == ' ' || line[i] == '\t'))
			v++;
		i++;
	}
	return (v);
}

int	count_map_lines(int fd)
{
	int		i;
	char	*line;

	i = 0;
	line = "full";
	while (line)
	{
		line = get_next_line(fd);
		if (line && is_valid_line(line))
			i++;
		free(line);
	}
	close (fd);
	return (i);
}
