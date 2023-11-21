/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aasselma <aasselma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 22:40:51 by aziyani           #+#    #+#             */
/*   Updated: 2023/11/20 23:56:53 by aasselma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../CUB3D.h"

int	part_two(s_main *m, int i)
{
	int	t;
	int	j;
	int	k;

	j = i - 1;
	k = 0;
	t = 0;
	while (m->map_db[++j])
		t++;
	m->map = ft_calloc(sizeof(char *), t + 1);
	j = i;
	while (m->map_db[j])
	{
		if (is_valid_line(m->map_db[j]))
		{
			m->map[k] = ft_strdup(m->map_db[j]);
			k++;
		}
		j++;
	}
	m->h = k;
	check_news(m, i);
	check_map(m, i, 0);
	return (0);
}

void	ft_help(char **s, t_check ch, s_main *m, int i)
{
	if (!s[0])
		ft_errorr("invalid map!");
	else if (!ft_strncmp("NO", s[0], 3))
		check_path(s, ch.no);
	else if (!ft_strncmp("SO", s[0], 3))
		check_path(s, ch.so);
	else if (!ft_strncmp("WE", s[0], 3))
		check_path(s, ch.we);
	else if (!ft_strncmp("EA", s[0], 3))
		check_path(s, ch.ea);
	else if (!ft_strncmp("C", s[0], 2))
		check_ceil(m->map_db[i], m);
	else if (!ft_strncmp("F", s[0], 2))
		check_floor(m->map_db[i], m);
	else
		ft_errorr("invalid map!");
}

int	part_one(s_main *m)
{
	char	**s;
	t_check	ch;
	int		i;
	int		j;

	ch = initialize_check();
	i = 0;
	j = 0;
	while (j < 6)
	{
		if (ft_strlen(m->map_db[i]) == 0)
		{
			i++;
			continue ;
		}
		s = ft_split(m->map_db[i], ' ');
		ft_help(s, ch, m, i);
		j++;
		i++;
	}
	part_two(m, i);
	return (0);
}

void	read_map(int fd, s_main *m, char **av)
{
	char	*line;
	int		i;
	int		j;

	i = 0;
	j = count_map_lines(fd);
	if (j == 0)
		ft_errorr("invalid param");
	m->map_db = (char **)malloc(sizeof(char *) * (j + 1));
	if (!m->map_db)
		ft_errorr("234");
	fd = open(av[1], O_RDONLY);
	while (i < j)
	{
		line = get_next_line(fd);
		if (line && is_valid_line(line))
		{
			m->map_db[i] = ft_strdup(line);
			if (m->map_db[i][ft_strlen(m->map_db[i]) - 1] == '\n')
				m->map_db[i][ft_strlen(m->map_db[i]) - 1] = '\0';
			i++;
		}
		free(line);
	}
	m->map_db[i] = NULL;
}

int	main(int ac, char **av)
{
	s_main	*m;
	int		fd;

	(void)(ac);
	m = malloc(sizeof(s_main));
	m->av = av[1];
	fd = open(av[1], O_RDONLY);
	if (fd == -1)
		ft_errorr("connot open this file");
	read_map(fd, m, av);
	txtrs_array(m);
	part_one(m);
	start_game(m);
}
