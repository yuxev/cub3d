/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcing2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aziyani <aziyani@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 11:34:30 by aziyani           #+#    #+#             */
/*   Updated: 2023/11/11 12:00:13 by aziyani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../CUB3D.h"

void	ft_errorr(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		write (2, &s[i], 1);
		i++;
	}
	write(2, "\n", 1);
	exit(1);
}

t_check	initialize_check(void)
{
	t_check	ch;

	ch.no = 0;
	ch.so = 0;
	ch.ea = 0;
	ch.we = 0;
	ch.c = 0;
	ch.f = 0;
	return (ch);
}

char	*skip_s(char *s)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	j = 0;
	str = NULL;
	while (s[i])
	{
		if (s[i] != ' ')
			str[j++] = s[i++];
		else
			i++;
	}
	return (str);
}

int	skip_spaces(char *s, int index)
{
	int	j;

	j = index;
	while (s[j] == ' ')
		j++;
	return (j);
}
