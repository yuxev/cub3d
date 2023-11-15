/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aasselma <aasselma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 11:45:47 by aziyani           #+#    #+#             */
/*   Updated: 2023/11/15 18:56:47 by aasselma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../CUB3D.h"

void	check_news(s_main *m, int i)
{
	int	j;

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
			j++;
		}
		i++;
	}
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
