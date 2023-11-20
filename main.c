/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aasselma <aasselma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 16:23:53 by aasselma          #+#    #+#             */
/*   Updated: 2023/11/20 22:12:16 by aasselma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "CUB3D.h"

void	get_small_distance(s_main *m, float c1, float c2)
{
	if (c2 >= c1)
	{
		m->is_vertcl = 0;
		m->goal_x = m->amodi_x;
		m->goal_y = m->amodi_y;
		m->distance = c1;
	}
	else
	{
		m->is_vertcl = 1;
		m->goal_x = m->ofo9i_x;
		m->goal_y = m->ofo9i_y;
		m->distance = c2;
	}
}

void	get_distance(s_main	*m, float pov)
{
	float	a;
	float	b;
	float	c1;
	float	c2;

	m->amodi_x = m->s_x + 1;
	m->amodi_y = m->s_y + 1;
	m->ofo9i_x = m->s_x + 1;
	m->ofo9i_y = m->s_y + 1;
	horz_raycasting(m, pov);
	vtcl_raycasting(m, pov);
	a = m->s_x - m->amodi_x;
	b = m->s_y - m->amodi_y;
	c1 = sqrt((a * a) + (b * b));
	a = m->s_x - m->ofo9i_x;
	b = m->s_y - m->ofo9i_y;
	c2 = sqrt((a * a) + (b * b));
	get_small_distance(m, c1, c2);
	m->distance = m->distance * cos((pov - m->pov) * RAD);
}

void	hook(void *param)
{
	s_main	*m;
	float	pov;
	float	fov;
	int		i;

	m = param;
	i = 0;
	mini_map(m);
	fov = 60;
	pov = m->pov - 30;
	ground_sky(m);
	ft_control(m);
	while (i <= WIDTH)
	{
		if (pov > 360)
			pov -= 360;
		else if (pov < 0)
			pov += 360;
		get_distance(m, pov);
		ft_texture(m, i);
		pov += fov / WIDTH;
		i++;
	}
}

int	start_game(s_main *m)
{
	m->mlx = mlx_init(WIDTH, HEIGH, "CUB3D", false);
	if (!(m->mlx))
	{
		puts(mlx_strerror(mlx_errno));
		return (EXIT_FAILURE);
	}
	m->g_image = mlx_new_image(m->mlx, WIDTH, HEIGH);
	mlx_image_to_window(m->mlx, m->g_image, 0, 0);
	m->image = mlx_new_image(m->mlx, WIDTH, HEIGH);
	mlx_image_to_window(m->mlx, m->image, 0, 0);
	m->txtr = malloc(4 * sizeof(mlx_texture_t));
	m->txtr[0] = *mlx_load_png(m->arr[0] + 3);
	m->txtr[1] = *mlx_load_png(m->arr[1] + 3);
	m->txtr[2] = *mlx_load_png(m->arr[2] + 3);
	m->txtr[3] = *mlx_load_png(m->arr[3] + 3);
	mlx_loop_hook(m->mlx, &hook, m);
	mlx_loop(m->mlx);
	return (EXIT_SUCCESS);
}
