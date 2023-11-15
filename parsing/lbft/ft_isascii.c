/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aziyani <aziyani@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 15:31:27 by aziyani           #+#    #+#             */
/*   Updated: 2022/10/21 19:11:17 by aziyani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isascii(int c)
{
	return (c >= 0 && c <= 127);
}
/*#include <stdio.h>
#include <ctype.h>

int main()
{
	printf ("%d\n", ft_isascii(- 1));
	printf ("%d", ft_isascii(- 1));
}*/