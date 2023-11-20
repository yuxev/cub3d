/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_control.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aasselma <aasselma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 17:10:08 by aasselma          #+#    #+#             */
/*   Updated: 2023/11/19 16:23:35 by aasselma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "CUB3D.h"

int	check_nm(s_main *m, float y, float x, int sign)
{
	float	s_y;
	float	s_x;

	s_y = (m->s_y + (y * DIC));
	s_x = (m->s_x + (x * DIC));
	if (sign == 0)
	{
		s_y = (m->s_y - (y * DIC));
		s_x = (m->s_x - (x * DIC));
	}
	if (m->map[(int)(s_y / CUB_SIZE)][(int)(m->s_x / CUB_SIZE)] == '1' 
		&& m->map[(int)(m->s_y / CUB_SIZE)][(int)(s_x / CUB_SIZE)] == '1')
		return (0);
	if (m->map[(int)(s_y / CUB_SIZE)][(int)(s_x / CUB_SIZE)] == '1')
		return (0);
	return (1);
}

void	ft_up_down(s_main *m)
{
	if (mlx_is_key_down(m->mlx, MLX_KEY_W)
		&& check_nm(m, sin(m->pov * RAD), cos(m->pov * RAD), 1))
	{
		m->s_y += sin(m->pov * RAD);
		m->s_x += cos(m->pov * RAD);
	}
	if (mlx_is_key_down(m->mlx, MLX_KEY_S)
		&& check_nm(m, sin(m->pov * RAD), cos(m->pov * RAD), 0))
	{
		m->s_y -= sin(m->pov * RAD);
		m->s_x -= cos(m->pov * RAD);
	}
}

void	ft_right_left(s_main *m)
{
	if (mlx_is_key_down(m->mlx, MLX_KEY_A)
		&& check_nm(m, sin((m->pov - 90) * RAD), cos((m->pov - 90) * RAD), 1))
	{
		m->s_y += sin((m->pov - 90) * RAD);
		m->s_x += cos((m->pov - 90) * RAD);
	}
	if (mlx_is_key_down(m->mlx, MLX_KEY_D)
		&& check_nm(m, sin((m->pov - 90) * RAD), cos((m->pov - 90) * RAD), 0))
	{
		m->s_y -= sin((m->pov - 90) * RAD);
		m->s_x -= cos((m->pov - 90) * RAD);
	}
}

void	ft_control(s_main *m)
{
	if (mlx_is_key_down(m->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(m->mlx);
	ft_up_down(m);
	ft_right_left(m);
	if (mlx_is_key_down(m->mlx, MLX_KEY_RIGHT))
		m->pov += 1.9;
	else if (mlx_is_key_down(m->mlx, MLX_KEY_LEFT))
		m->pov -= 1.9;
	if (m->pov > 360)
		m->pov -= 360;
	if (m->pov < 0)
		m->pov += 360;
	draw_player(m->s_x, m->s_y, m->image);
}
