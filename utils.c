/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aasselma <aasselma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 17:45:01 by aasselma          #+#    #+#             */
/*   Updated: 2023/11/19 18:06:31 by aasselma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "CUB3D.h"

int	get_rgba(int r, int g, int b, int a)
{
	return (r << 24 | g << 16 | b << 8 | a);
}

void	ground_sky(s_main *m)
{
	int	y;
	int	x;

	y = 0;
	while (y != HEIGH)
	{
		x = 1;
		while (x != WIDTH)
		{
			if (y <= (HEIGH / 2))
				mlx_put_pixel(m->g_image, x, y,
					get_rgba(m->sky[0], m->sky[1], m->sky[2], 255));
			else
				mlx_put_pixel(m->g_image, x, y,
					get_rgba(m->floor[0], m->floor[1], m->floor[2], 255));
			x++;
		}
		y++;
	}
}
