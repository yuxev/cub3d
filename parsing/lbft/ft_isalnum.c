/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aziyani <aziyani@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 15:18:21 by aziyani           #+#    #+#             */
/*   Updated: 2022/10/21 19:11:15 by aziyani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)
{
	return (ft_isalpha(c) || ft_isdigit(c));
}
/*#include <stdio.h>
#include <ctype.h>

int main()
{
    printf ("%d\n", ft_isalnum('.'));
    printf ("%d", ft_isalnum('.'));
}*/