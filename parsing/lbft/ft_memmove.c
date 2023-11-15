/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aasselma <aasselma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 19:30:49 by aziyani           #+#    #+#             */
/*   Updated: 2023/11/11 17:05:47 by aasselma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*d;
	unsigned char	*s;

	d = (unsigned char *)dst;
	s = (unsigned char *)src;
	if (dst == src)
		return (dst);
	if (dst < src)
	{
		ft_memcpy(d, s, len);
	}
	else
	{
		while (len-- > 0)
		{
			d[len] = s[len];
		}
	}
	return (d);
}
