/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aasselma <aasselma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 05:34:25 by aasselma          #+#    #+#             */
/*   Updated: 2023/11/19 16:35:57 by aasselma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "CUB3D.h"

void	draw_map(mlx_image_t *img, int32_t y, int32_t x, int32_t clr)
{
	int32_t	w;
	int32_t	h;
	int32_t	s;

	s = CUB_SIZE;
	w = s * x;
	h = s * y;
	y = 0;
	x = 0;
	while (y != s)
	{
		while (x != CUB_SIZE)
		{
			mlx_put_pixel(img, w / MIN, h / MIN, clr);
			x++;
			w++;
		}
		x = 0;
		w -= CUB_SIZE;
		h++;
		y++;
	}
}

void	initialize_player_pov(s_main *m, char c)
{
	if (c == 'E')
		m->pov = 0;
	if (c == 'N')
		m->pov = 90;
	if (c == 'W')
		m->pov = 180;
	if (c == 'S')
		m->pov = 270;
}

void	mini_map(s_main *m)
{
	int	y;
	int	x;

	y = 0;
	while (m->map[y] != NULL)
	{
		x = 0;
		while (m->map[y][x])
		{
			if (m->map[y][x] == '1')
				draw_map(m->image, y, x, W_COLOR);
			else if (m->map[y][x] == '0')
				draw_map(m->image, y, x, G_COLOR);
			if (m->map[y][x] == 'N' || m->map[y][x] == 'S'
				|| m->map[y][x] == 'E' || m->map[y][x] == 'W')
			{
				m->s_x = (x * CUB_SIZE) + 18;
				m->s_y = (y * CUB_SIZE) + 18;
				initialize_player_pov(m, m->map[y][x]),
				m->map[y][x] = '0';
			}
			x++;
		}
		y++;
	}
}
