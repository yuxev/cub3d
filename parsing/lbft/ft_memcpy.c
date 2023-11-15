/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aziyani <aziyani@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 18:58:41 by aziyani           #+#    #+#             */
/*   Updated: 2022/10/21 19:11:35 by aziyani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*d;
	unsigned char	*s;
	size_t			i;

	d = (unsigned char *)dst;
	s = (unsigned char *)src;
	i = 0;
	if (d == 0 && s == 0)
		return (0);
	while (i < n)
	{
		d[i] = s[i];
		i++;
	}
	return (d);
}
/*#include <stdio.h>
#include <string.h>

int main ()
{
   const char src[50] = "memory";
   char dest[50];
   strcpy(dest,"helloworld");
   printf("Before memcpy dest = %s\n", dest);
   memcpy(dest + 2, dest, 6);
   printf("After memcpy dest = %s\n", dest);
   memmove(dest + 2, dest, 6);
   printf("After memcpy dest = %s\n", dest);
   
   return(0);
}*/