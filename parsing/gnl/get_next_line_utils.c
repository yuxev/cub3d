/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aasselma <aasselma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 02:27:13 by aasselma          #+#    #+#             */
/*   Updated: 2022/11/22 23:51:42 by aasselma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(char *string)
{
	int	i;

	i = 0;
	if (!(string))
		return (0);
	while (string[i])
		i++;
	return (i);
}

int	ft_countline(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '\n')
		{
			i++;
			break ;
		}
		i++;
	}
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*p;
	size_t	x;

	x = 0;
	if (!s1 && !s2)
		return (NULL);
	p = malloc((ft_strlen(s1) + ft_strlen(s2)) + 1);
	if (s1)
	{
		while (s1[x])
		{
			p[x] = s1[x];
			x++;
		}
	}
	x = 0;
	while (s2[x])
	{
		p[ft_strlen(s1) + x] = s2[x];
		x++;
	}
	p[ft_strlen(s1) + ft_strlen(s2)] = '\0';
	free(s1);
	return (p);
}

char	*ft_getline(char *str, int *len)
{
	char	*line;

	line = malloc(ft_countline(str) + 1);
	while (str[*len])
	{
		line[*len] = str[*len];
		if (str[*len] == '\n')
		{
			*len += 1;
			break ;
		}
		*len += 1;
	}
	if (*len == 0 && str[*len] == '\0')
	{
		free(line);
		return (NULL);
	}
	line[*len] = '\0';
	while (str[*len] != '\0')
		*len += 1;
	return (line);
}

char	*ft_getafterline(char *str, int len)
{
	char	*p;
	int		i;
	int		k;

	i = 0;
	k = 0;
	if (ft_strlen(str) == 0)
	{
		if (str)
			free(str);
		return (NULL);
	}
	p = malloc(len + 1);
	i = ft_countline(str);
	while (str[i] != '\0')
	{
		p[k] = str[i];
		i++;
		k++;
	}
	p[k] = '\0';
	free(str);
	return (p);
}
