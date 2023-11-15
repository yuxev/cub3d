/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aziyani <aziyani@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 11:40:24 by aziyani           #+#    #+#             */
/*   Updated: 2023/11/11 13:21:48 by aziyani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../CUB3D.h"

void	check_map(s_main *m, int i)
{
	int	j;

	while (m->map_db[i])
	{
		j = 0;
		while (m->map_db[i][j])
		{
			if (m->map_db[i][j] == '0')
			{
				if (m->map_db[i][j + 1] == ' ' || m->map_db[i][j + 1] == '\0')
					ft_errorr("211");
				if (m->map_db[i][j - 1] == ' ' || m->map_db[i][j - 1] == '\0')
					ft_errorr("213");
				if ((m->map_db[i] && m->map_db[i - 1][j] == ' ')
					|| m->map_db[i - 1][j] == '\0')
					ft_errorr("215");
				if ((m->map_db[i] && m->map_db[i + 1][j] == ' ')
					|| m->map_db[i + 1][j] == '\0')
					ft_errorr("217");
			}
			j++;
		}
		i++;
	}
}

char	*check_f(char *str)
{
	char	*res;
	int		i;
	int		j;

	i = 0;
	j = 0;
	res = malloc(ft_strlen(str));
	while (str[i])
	{
		if (str[i] == 'F')
			i++;
		res[j] = str[i];
		i++;
		j++;
	}
	res[j] = '\0';
	return (res);
}

int	check_floor(char *s, s_main *cub)
{
	int		j;
	int		count;
	char	**str;
	char	*s1;

	s1 = check_f(s);
	str = ft_split(s1, ',');
	count = ft_count(s1);
	if (str[0] && str[1] && str[2] && !str[3] && count == 2)
	{
		j = 0;
		cub->floor[0] = ft_atoi(str[0]);
		if (cub->floor[0] < 0 || cub->floor[0] > 256)
			ft_errorr("more than 255");
		cub->floor[1] = ft_atoi(str[1]);
		if (cub->floor[1] < 0 || cub->floor[1] > 256)
			ft_errorr("more than 255");
		cub->floor[2] = ft_atoi(str[2]);
		if (cub->floor[2] < 0 || cub->floor[2] > 256)
			ft_errorr("more than 255");
	}
	else
		ft_errorr("bad arguments");
	return (1);
}

char	*check_c(char *str)
{
	int		i;
	int		j;
	char	*res;

	i = 0;
	j = 0;
	res = malloc(ft_strlen(str));
	while (str[i])
	{
		if (str[i] == 'C')
			i++;
		res[j] = str[i];
		i++;
		j++;
	}
	res[j] = '\0';
	return (res);
}

void	check_ceil(char *s, s_main *cub)
{
	char	**str;
	char	*s1;
	int		count;

	s1 = check_c(s);
	str = ft_split(s1, ',');
	count = ft_count(s1);
	if (str[0] && str[1] && str[2] && !str[3] && count == 2)
	{
		cub->sky[0] = ft_atoi(str[0]);
		if (cub->sky[0] < 0 || cub->sky[0] > 256)
			ft_errorr("more than 255");
		cub->sky[1] = ft_atoi(str[1]);
		if (cub->sky[1] < 0 || cub->sky[1] > 256)
			ft_errorr("more than 255");
		cub->sky[2] = ft_atoi(str[2]);
		if (cub->sky[2] < 0 || cub->sky[2] > 256)
			ft_errorr("more than 255");
	}
	else
		ft_errorr("bad arguments");
}
