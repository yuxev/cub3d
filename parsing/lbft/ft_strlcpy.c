/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aziyani <aziyani@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 11:29:03 by aziyani           #+#    #+#             */
/*   Updated: 2022/10/21 19:12:04 by aziyani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	len;
	char	*csrc;

	csrc = (char *)src;
	len = ft_strlen(csrc);
	if (dstsize == 0)
		return (len);
	i = 0;
	if (dstsize > 0)
	{
		while ((i < dstsize - 1) && (csrc[i] != '\0'))
		{
			dst[i] = csrc[i];
			i++;
		}
	}
	dst[i] = '\0';
	return (len);
}
/*#include <string.h>
#include <stdio.h>

int main()
{
	unsigned char	s[]	= "hello";
	unsigned char	d[]	= "world";
	printf ("%zu\n", ft_strlcpy(d, s, 0));
	printf ("%zu", strlcpy(d, s, 0));
}*/
