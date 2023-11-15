/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aasselma <aasselma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 16:19:32 by aasselma          #+#    #+#             */
/*   Updated: 2023/11/14 01:31:45 by aasselma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "CUB3D.h"

void	texture_image(s_main *m, t_point txt, t_point img, mlx_texture_t *txtr)
{
	uint8_t*	pixelx;
	uint8_t*	pixeli;
	float		d;
	d = txtr->height / m->wall_h;
	while((int) img.y < m->last_wall_p)
	{
		if ((((int)txt.y * txtr->width) + (int)txt.x) < (txtr->width * txtr->height)
		 	&& (img.y > 0  && img.x > 0) && (img.y < m->g_image->height && img.x < m->g_image->width))
		{
			pixelx = &txtr->pixels[(((int)txt.y * txtr->width) + (int)txt.x)
						* txtr->bytes_per_pixel];
			pixeli = &m->g_image->pixels[(((int)img.y * m->g_image->width) + (int)img.x)
						* txtr->bytes_per_pixel];
			ft_memmove(pixeli, pixelx, txtr->bytes_per_pixel);
		}
		img.y++;
		txt.y += d;
	}
}

