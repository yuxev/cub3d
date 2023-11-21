/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aasselma <aasselma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 16:19:32 by aasselma          #+#    #+#             */
/*   Updated: 2023/11/21 10:51:28 by aasselma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "CUB3D.h"

void	texture_image(s_main *m, t_point txt, t_point img, mlx_texture_t *txtr)
{
	uint8_t	*pixelx;
	uint8_t	*pixeli;
	float	d;

	d = txtr->height / m->wall_h;
	while ((int) img.y < m->last_wall_p)
	{
		if ((((int)txt.y * txtr->width) + (int)txt.x)
			< (txtr->width * txtr->height)
			&& (img.y > 0 && img.x > 0) && (img.y < m->g_image->height
				&& img.x < m->g_image->width))
		{
			pixelx = &txtr->pixels[(((int)txt.y * txtr->width) + (int)txt.x)
				* txtr->bytes_per_pixel];
			pixeli = &m->g_image->pixels[(((int)img.y * m->g_image->width)
					+ (int)img.x) * txtr->bytes_per_pixel];
			ft_memmove(pixeli, pixelx, txtr->bytes_per_pixel);
		}
		img.y++;
		txt.y += d;
	}
}

void	horz_texture(s_main *m, t_point img, t_point txt)
{
	if (fmod(m->goal_x, CUB_SIZE) == 0)
	{
		txt.x = fmod(m->goal_y, CUB_SIZE) * (m->txtr->width / CUB_SIZE);
		texture_image(m, txt, img, &m->txtr[0]);
	}
	else if (fmod(m->goal_x, CUB_SIZE) > CUB_SIZE - 0.00015)
	{
		txt.x = fmod(m->goal_y, CUB_SIZE) * (m->txtr->width / CUB_SIZE);
		texture_image(m, txt, img, &m->txtr[2]);
	}
}

void	vtcl_texture(s_main *m, t_point img, t_point txt)
{
	if (fmod(m->goal_y, CUB_SIZE) == 0)
	{
		txt.x = fmod(m->goal_x, CUB_SIZE) * (m->txtr->width / CUB_SIZE);
		texture_image(m, txt, img, &m->txtr[3]);
	}
	else if (fmod(m->goal_y, CUB_SIZE) > CUB_SIZE - 0.00015)
	{
		txt.x = fmod(m->goal_x, CUB_SIZE) * (m->txtr->width / CUB_SIZE);
		texture_image(m, txt, img, &m->txtr[1]);
	}
}

void	ft_texture(s_main *m, int i)
{
	t_point	p1;
	t_point	p2;
	t_point	img;
	t_point	txt;
	float	v;

	v = (HEIGH / m->distance) * CUB_SIZE;
	p1.x = i;
	p1.y = (HEIGH / 2) - (v / 2);
	p2.x = i;
	p2.y = (HEIGH / 2) + (v / 2);
	img.y = p1.y;
	img.x = i;
	txt.y = 0;
	m->wall_h = v;
	m->last_wall_p = p2.y;
	if (m->is_vertcl == 0)
		horz_texture(m, img, txt);
	else
		vtcl_texture(m, img, txt);
}
