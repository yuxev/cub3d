/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aziyani <aziyani@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 16:52:30 by aziyani           #+#    #+#             */
/*   Updated: 2022/10/21 19:11:19 by aziyani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isprint(int c)
{
	return (c >= 32 && c <= 126);
}
/*#include <stdio.h>
#include <ctype.h>

int main()
{
	printf ("%d\n", ft_isprint(-1));
	printf ("%d", ft_isprint(-1));
}*/