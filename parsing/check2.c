/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aasselma <aasselma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 11:45:47 by aziyani           #+#    #+#             */
/*   Updated: 2023/11/20 19:30:53 by aasselma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../CUB3D.h"

void	check_player(char c, int *count)
{
	if (ft_strchr("NSWE", c))
		(*count)++;
}

void	check_news(s_main *m, int i)
{
	int	j;
	int	count;

	count = 0;
	while (m->map_db[i])
	{
		j = 0;
		while (m->map_db[i][j])
		{
			if (m->map_db[i][j] != '1' && m->map_db[i][j] != '0'
				&& m->map_db[i][j] != 'N' && m->map_db[i][j] != 'E'
					&& m->map_db[i][j] != 'W' && m->map_db[i][j] != 'S'
						&& m->map_db[i][j] != ' ')
				ft_errorr("your map not valid");
			check_player(m->map_db[i][j], &count);
			j++;
		}
		i++;
	}
	if (count != 1)
		ft_errorr("your map not valid");
}

int	check_path(char **s, int ch)
{
	int	i;
	int	fd;

	i = 0;
	while (s[i])
		i++;
	if (i != 2)
		ft_errorr("49");
	if (ch == 1)
		ft_errorr("52");
	ch = 1;
	fd = open(s[1], O_RDONLY);
	if (fd == -1)
		ft_errorr("57");
	return (1);
}

void	txtrs_array(s_main	*m)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	m->arr = malloc(sizeof(char *) * 7);
	while (m->map_db[i])
	{
		if (i < 6)
		{
			if (!ft_strncmp(m->map_db[i], "NO", 2) 
				|| !ft_strncmp(m->map_db[i], "SO", 2) 
				|| !ft_strncmp(m->map_db[i], "EA", 2) 
				|| !ft_strncmp(m->map_db[i], "WE", 2))
				{	
					m->arr[j] = m->map_db[i];
					j++;
				}
		}
		i++;
	}
	m->arr[j] = NULL;
}
