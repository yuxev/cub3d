/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vtcl_raycasting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aasselma <aasselma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 04:34:49 by aasselma          #+#    #+#             */
/*   Updated: 2023/11/15 23:13:05 by aasselma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "CUB3D.h"

int	checker(s_main *m, int w_y, int w_x)
{
	if (((int)(w_y) / CUB_SIZE) >= m->h || ((int)(w_y) / CUB_SIZE) < 0)
		return (0);
	if (((size_t)(w_x) / CUB_SIZE) >= ft_strlen(m->map[(int)(w_y) / CUB_SIZE])
		|| ((int)(w_x) / CUB_SIZE) < 0)
		return (0);
	if (m->map[(int)(w_y) / CUB_SIZE][(int)(w_x / CUB_SIZE)] == '1')
		return (0);
	return (1);
}

void	vtcl_raycasting(s_main *m, float pov)
{
	float	f_x;
	float	f_y;

	m->amodi_y = 0;
	m->amodi_x = 0;
	if (pov == 90 || pov == 270)
		return ;
	if (pov > 90 && pov < 270)
	{
		m->amodi_x = (((int)(m->s_x / CUB_SIZE)) * CUB_SIZE) - 0.0001;
		f_x = -CUB_SIZE;
	}
	else
	{
		m->amodi_x = ((int)(m->s_x / CUB_SIZE) + 1) * CUB_SIZE;
		f_x = CUB_SIZE;
	}
	m->amodi_y = (-(m->s_x - m->amodi_x) * tan(pov * RAD)) + m->s_y;
	f_y = (f_x * tan(pov * RAD));
	while (checker(m, m->amodi_y, m->amodi_x))
	{
		m->amodi_y += f_y;
		m->amodi_x += f_x;
	}
}

void	horz_raycasting(s_main	*m, float pov)
{
	float	f_x;
	float	f_y;

	m->ofo9i_y = 0;
	m->ofo9i_x = 0;
	if (pov == 0 || pov == 180 || pov == 360)
		return ;
	if (pov > 180 && pov < 360)
	{
		m->ofo9i_y = (((int)(m->s_y / CUB_SIZE)) * CUB_SIZE) - 0.0001;
		f_y = -CUB_SIZE;
	}
	else
	{
		m->ofo9i_y = ((int)(m->s_y / CUB_SIZE) + 1) * CUB_SIZE;
		f_y = CUB_SIZE;
	}
	m->ofo9i_x = (-(m->s_y - m->ofo9i_y) / tan(pov * RAD)) + m->s_x;
	f_x = (f_y / tan(pov * RAD));
	while (checker(m, m->ofo9i_y, m->ofo9i_x))
	{
		m->ofo9i_y += f_y;
		m->ofo9i_x += f_x;
	}
}

void	draw_player(float x, float y, mlx_image_t *img)
{
	int	r_x;
	int	r_y;
	int	i;
	int	j;

	r_y = y;
	j = 0;
	while (j != 10)
	{
		i = 0;
		r_x = (x - (10 / 2));
		while (i != 10)
		{
			if (((r_x / MIN) > 0 && (r_x / MIN) <= (WIDTH)) 
				&& ((r_y / MIN) > 0 && (r_y / MIN) <= (HEIGH)))
				mlx_put_pixel(img, (r_x / MIN), (r_y / MIN), 0x53f0FFF);
			i++;
			r_x++;
		}
		j++;
		r_y++;
	}
}
