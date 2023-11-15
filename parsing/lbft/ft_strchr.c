/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aziyani <aziyani@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 18:51:57 by aziyani           #+#    #+#             */
/*   Updated: 2022/10/21 19:11:46 by aziyani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char			*ss;
	int				i;
	unsigned char	cc;

	cc = c;
	ss = (char *)s;
	i = 0;
	while (ss[i])
	{
		if (ss[i] == cc)
			return (&ss[i]);
		i++;
	}
	if (cc == '\0')
		return (&ss[ft_strlen(s)]);
	return (0);
}
