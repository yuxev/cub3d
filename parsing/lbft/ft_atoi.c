/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aziyani <aziyani@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 19:57:30 by aziyani           #+#    #+#             */
/*   Updated: 2022/10/21 19:11:09 by aziyani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int	i;
	int	signe;
	int	result;

	signe = 1;
	result = 0;
	i = 0;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			signe = signe * -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
			result = (result * 10) + (str[i] - 48);
		i++;
	}
	return (result * signe);
}
/*#include <string.h>
#include <stdio.h>

int main(int ac, char **av)
{
    char s[] = "123";
    printf ("mine : %d\n", ft_atoi(av[1]));
    printf ("%d", atoi(av[1]));
    
}*/
