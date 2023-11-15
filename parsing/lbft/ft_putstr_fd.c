/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aziyani <aziyani@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 18:36:18 by aziyani           #+#    #+#             */
/*   Updated: 2022/10/21 19:11:44 by aziyani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	if (s)
	{
		while (*s)
		{
			write(fd, s, 1);
			s++;
		}
	}
}
// #include <stdio.h>

// int main()
// {
//     char *s;
//     int fd;
//     s = "ayoub lantaki kaydrab wytaki";
//     fd = open("zizo",O_RDWR);
//     printf("%d", fd);
//     ft_putstr_fd(s, fd);
// }