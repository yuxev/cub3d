/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aziyani <aziyani@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 18:21:10 by aziyani           #+#    #+#             */
/*   Updated: 2022/10/21 19:11:45 by aziyani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	cword(char const *ptr, char cep)
{
	int	i;
	int	x;

	i = 0;
	x = 0;
	while (ptr[i])
	{
		while (ptr[i] == cep && ptr[i])
			i++;
		if (ptr[i])
			x++;
		while (ptr[i] != cep && ptr[i])
			i++;
	}
	return (x);
}

char	**ft_split(char const *s, char c)
{
	char	**ss;
	int		i;
	int		len;
	int		countage;

	if (!s)
		return (0);
	ss = malloc(sizeof(char *) * (cword(s, c) + 1));
	if (!ss)
		return (0);
	i = 0;
	len = 0;
	countage = 0;
	while (countage < cword(s, c))
	{
		while (s[len] == c && s[len])
			len++;
		if (s[len] && s[len] != c)
			i = len;
		while (s[len] != c && s[len])
			len++;
		ss[countage++] = ft_substr(s, i, len - i);
	}
	ss[countage] = 0;
	return (ss);
}
