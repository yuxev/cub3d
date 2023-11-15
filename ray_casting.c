/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aasselma <aasselma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 04:34:49 by aasselma          #+#    #+#             */
/*   Updated: 2023/11/14 05:05:56 by aasselma         ###   ########.fr       */
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

void	ray_casting__(s_main *m, float pov)
{
	float	f_x;
	float	f_y;

	m->ofo9i_y = 0;
	m->ofo9i_x = 0;
	if (pov == 90 || pov == 270)
		return ;
	if (pov > 90 && pov < 270)
	{
		m->ofo9i_x = (((int)(m->s_x / CUB_SIZE)) * CUB_SIZE) - 0.0001;
		f_x = -CUB_SIZE;
	}
	else
	{
		m->ofo9i_x = ((int)(m->s_x / CUB_SIZE) + 1) * CUB_SIZE;
		f_x = CUB_SIZE;
	}
	m->ofo9i_y = (-(m->s_x - m->ofo9i_x) * tan(pov * RAD)) + m->s_y;
	f_y = (f_x * tan(pov * RAD));
	while (checker(m, m->ofo9i_y, m->ofo9i_x))
	{
		m->ofo9i_y += f_y;
		m->ofo9i_x += f_x;
	}
}

void	ray_casting(s_main	*m, float pov)
{
	float	f_x;
	float	f_y;

	m->amodi_y = 0;
	m->amodi_x = 0;
	if (pov == 0 || pov == 180 || pov == 360)
		return ;
	if (pov > 180 && pov < 360)
	{
		m->amodi_y = (((int)(m->s_y / CUB_SIZE)) * CUB_SIZE) - 0.0001;
		f_y = -CUB_SIZE;
	}
	else
	{
		m->amodi_y = ((int)(m->s_y / CUB_SIZE) + 1) * CUB_SIZE;
		f_y = CUB_SIZE;
	}
	m->amodi_x = (-(m->s_y - m->amodi_y) / tan(pov * RAD)) + m->s_x;
	f_x = (f_y / tan(pov * RAD));
	while (checker(m, m->amodi_y, m->amodi_x))
	{
		m->amodi_y += f_y;
		m->amodi_x += f_x;
	}
}

void	start_drawing(s_main *m, float ydiff, float xdiff, float mdiff)
{
	float	r_x;
	float	r_y;
	int		i;

	r_x = m->s_x;
	r_y = m->s_y;
	i = -1;
	while (++i < mdiff)
	{
		if (((r_x / MIN) > 0 && (r_x / MIN) <= (WIDTH)) 
			&& ((r_y / MIN) > 0 && (r_y / MIN) <= (HEIGH)))
			mlx_put_pixel(m->image, (int)(r_x / MIN),
				(int)(r_y / MIN), 0x53f0FFF);
		r_x += xdiff;
		r_y += ydiff;
	}
}

void	draw_line(s_main *m, float x2, float y2)
{
	float	xdiff;
	float	ydiff;
	float	max_diff;

	xdiff = x2 - m->s_x;
	ydiff = y2 - m->s_y;
	max_diff = fabs(xdiff);
	if (fabs(xdiff) < fabs(ydiff))
		max_diff = fabs(ydiff);
	xdiff = xdiff / max_diff;
	ydiff = ydiff / max_diff;
	start_drawing(m, ydiff, xdiff, max_diff);
}
