/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aziyani <aziyani@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 19:27:19 by aziyani           #+#    #+#             */
/*   Updated: 2022/10/21 19:11:42 by aziyani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	char			c;
	long long int	i;

	i = n;
	if (i < 0)
	{
		i = i * -1;
		write(fd, "-", 1);
	}
	if (i <= 9)
	{
		c = i + '0';
		write(fd, &c, 1);
	}
	if (i > 9)
	{
		ft_putnbr_fd(i / 10, fd);
		ft_putnbr_fd(i % 10, fd);
	}
}
