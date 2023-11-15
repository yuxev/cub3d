/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aziyani <aziyani@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 17:35:38 by aziyani           #+#    #+#             */
/*   Updated: 2022/10/21 19:11:38 by aziyani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*re;
	size_t			i;

	re = (unsigned char *)b;
	i = 0;
	while (i < len)
	{
		re[i] = c;
		i++;
	}
	return (re);
}
/*#include <string.h>
int main () {
   char str[50];

   strcpy(str,"This is");
   puts(str);

   ft_memset(str,'$',8);
   puts(str);
   
   return(0);
}*/