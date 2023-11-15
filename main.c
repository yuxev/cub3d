/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aasselma <aasselma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 16:23:53 by aasselma          #+#    #+#             */
/*   Updated: 2023/11/15 19:02:37 by aasselma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "CUB3D.h"

void	get_distance(s_main	*m, float  pov)
{
	m->amodi_x = m->s_x + 1;
	m->amodi_y = m->s_y + 1;
	m->ofo9i_x = m->s_x + 1;
	m->ofo9i_y = m->s_y + 1;
	ray_casting__(m, pov);
	ray_casting(m, pov);
	float	a;
	float	b;
	float	c1;
	float	c2;

	a = m->s_x - m->amodi_x;
	b = m->s_y - m->amodi_y;
	c1 = sqrt((a * a) + (b * b));
	a = m->s_x - m->ofo9i_x;
	b = m->s_y - m->ofo9i_y;
	c2 = sqrt((a * a) + (b * b));
	if (c2 <= c1)
	{
		m->goal_x = m->ofo9i_x;
		m->goal_y = m->ofo9i_y;
		m->distance = c2;
	}
	else
	{
		m->goal_x = m->amodi_x;
		m->goal_y = m->amodi_y;
		m->distance = c1;
	}
	draw_line(m, m->goal_x, m->goal_y);
	m->distance = m->distance * cos((pov - m->pov) * RAD);
}

void	draw_walls(s_main *m, int i)
{
	t_point p1;
	t_point p2;
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
	if (fmod(m->goal_y, CUB_SIZE) == 0)
	{
		txt.x = fmod(m->goal_x, CUB_SIZE) * (m->txtr->width / CUB_SIZE);
		texture_image(m, txt, img, &m->txtr[0]);
	}
	else if (fmod(m->goal_y, CUB_SIZE) > CUB_SIZE - 0.00015)
	{
		txt.x = fmod(m->goal_x, CUB_SIZE) * (m->txtr->width / CUB_SIZE);
		texture_image(m, txt, img, &m->txtr[1]);
	}
	if (fmod(m->goal_x, CUB_SIZE) == 0)
	{
		txt.x = fmod(m->goal_y, CUB_SIZE) * (m->txtr->width / CUB_SIZE);
		texture_image(m, txt, img, &m->txtr[2]);
	}
	else if (fmod(m->goal_x, CUB_SIZE) > CUB_SIZE - 0.00015)
	{
		txt.x = fmod(m->goal_y, CUB_SIZE) * (m->txtr->width / CUB_SIZE);
		texture_image(m, txt, img, &m->txtr[3]);
	}
}

void	hook(void* param)
{
	s_main*		m;
	m = param;

	mini_map(m);
	int	i = 0;
	float	pov = m->pov - 30;
	float	fov = 60;
	float	rays = WIDTH;
	int	yy;
	int	xx;
	yy = 0;
	while(yy != HEIGH)
	{
		xx = 0;
		while(xx != WIDTH)
		{
			if (yy <= (HEIGH / 2))
				mlx_put_pixel(m->g_image, xx++, yy, 0x87CEEBFF);
			else
				mlx_put_pixel(m->g_image, xx++, yy, 0x151F2CFF);
		}
		yy++;
	}
	while(i <= rays)
	{
		if (pov > 360)
			pov -= 360;
		else if (pov < 0)
			pov += 360;
		get_distance(m, pov);
		draw_walls(m, i);
		pov += fov / rays;
		i++;
	}
}


int	check_nm(s_main *m, float y, float x, int sign)
{
	float	s_y;
	float	s_x;

	s_y	= (m->s_y + (y * 5));
	s_x	= (m->s_x + (x * 5));
	if (sign == 0)
	{
		s_y	= (m->s_y - (y * 5));
		s_x	= (m->s_x - (x * 5));
	}
	if (m->map[(int)(s_y / CUB_SIZE)][(int)(m->s_x / CUB_SIZE)] == '1' 
		&& m->map[(int)(m->s_y / CUB_SIZE)][(int)(s_x / CUB_SIZE)] == '1')
		return (0);
	if (m->map[(int)(s_y / CUB_SIZE)][(int)(s_x / CUB_SIZE)] == '1')
		return (0);
	return (1);
}

void	player_moves(void	*param)
{
	s_main	*m;

	m = param;
	if (mlx_is_key_down(m->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(m->mlx);
	if (mlx_is_key_down(m->mlx, MLX_KEY_W) && check_nm(m, sin(m->pov * RAD), cos(m->pov * RAD), 1))
	{
		m->s_y += sin(m->pov * RAD);
		m->s_x += cos(m->pov * RAD);
	}
	if (mlx_is_key_down(m->mlx, MLX_KEY_S) && check_nm(m, sin(m->pov * RAD), cos(m->pov * RAD), 0))
	{
		m->s_y -= sin(m->pov * RAD);
		m->s_x -= cos(m->pov * RAD);
	}
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
	if (mlx_is_key_down(m->mlx, MLX_KEY_RIGHT))
		m->pov += 1.9;
	else if (mlx_is_key_down(m->mlx, MLX_KEY_LEFT))
		m->pov -= 1.9;
	if (m->pov > 360)
		m->pov -= 360;
	if (m->pov < 0)
		m->pov += 360;
}

int start_game(s_main *m)
{
	if (!(m->mlx = mlx_init(WIDTH, HEIGH, "CUB3D", false)))
	{
		puts(mlx_strerror(mlx_errno));
		return(EXIT_FAILURE);
	}
	m->g_image = mlx_new_image(m->mlx, WIDTH, HEIGH);
	mlx_image_to_window(m->mlx, m->g_image, 0, 0);
	m->image = mlx_new_image(m->mlx, WIDTH, HEIGH);
	mlx_image_to_window(m->mlx, m->image, 0, 0);
	m->txtr = malloc(4 * sizeof(mlx_texture_t));
	m->txtr[0] = *mlx_load_png(m->map_db[0] + 3);
	m->txtr[1] = *mlx_load_png(m->map_db[1] + 3);
	m->txtr[2] = *mlx_load_png(m->map_db[2] + 3);
	m->txtr[3] = *mlx_load_png(m->map_db[3] + 3);
	mlx_loop_hook(m->mlx, &hook, m);
	mlx_loop_hook(m->mlx, &player_moves, m);
	mlx_loop(m->mlx);
	return (EXIT_SUCCESS);
}
