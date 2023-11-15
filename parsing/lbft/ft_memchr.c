/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aziyani <aziyani@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 11:31:31 by aziyani           #+#    #+#             */
/*   Updated: 2022/10/21 19:11:23 by aziyani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*ss;

	ss = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		if (ss[i] == (unsigned char)c)
			return (&ss[i]);
		i++;
	}
	return (0);
}
/*#include <stdio.h>
#include <string.h>

int main()
{
	char ss[] = "ayoub";
	printf("%s\n", ft_memchr(ss, 'o', 3));
	printf("%s", memchr(ss, 'o', 3));
}*/