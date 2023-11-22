/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CUB3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aziyani <aziyani@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 16:10:27 by aziyani           #+#    #+#             */
/*   Updated: 2023/11/22 01:35:19 by aziyani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

#include "parsing/gnl/get_next_line.h"
#include "parsing/lbft/libft.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <stdbool.h>
#include "MLX42/include/MLX42/MLX42.h"
# include <fcntl.h>
# include <stdio.h>
#include <stdbool.h>

#define CUB_SIZE 20
#define WIDTH 1080
#define HEIGH 900
#define MIN 3
#define DIC 5
#define W_COLOR 0x960F18FF
#define G_COLOR 0XB9B3B3FF
#define P_COLOR 0x114E61FF
#define RAD 0.0174532925

typedef struct s_point
{
	float	x;
	float	y;
} t_point;

typedef struct
{
	int				is_vertcl;
	int				sky[3];
	int				floor[3];
	char			**map_db;
	char			**map;
	char			**arr;
	char			*av;
	int				w;
	int				h;
	float			wall_h;
	float			last_wall_p;
	float			distance;
	float			goal_x;
	float			goal_y;
	float			ofo9i_x;
	float			ofo9i_y;
	float			amodi_x;
	float			amodi_y;
	float			s_x;
	float			s_y;
	float			pov;
	mlx_texture_t	*txtr;
    mlx_t*			mlx;
    mlx_image_t		*image;
    mlx_image_t		*g_image;
} s_main;


typedef struct s_check {
	int	no;
	int	we;
	int	ea;
	int	so;
	int	c;
	int	f;
}		t_check;


int		start_game(s_main *m);
void	horz_raycasting(s_main *m, float pov);
void	vtcl_raycasting(s_main *m, float pov);
int		get_rgba(int r, int g, int b, int a);
void	ground_sky(s_main *m);
void	draw_player(float x, float y, mlx_image_t *img);
void	ft_control(s_main *m);
void	mini_map(s_main *m);
void	ft_texture(s_main *m, int i);


/*----------------------------PARCING-------------------------------*/
void	check_floor(char *s, s_main *cub, char	**str, char	*s1);
void	check_ceil(char *s, s_main *cub, char	**str, char	*s1);
void	check_map(s_main *m, int i, int j);
void	check_news(s_main *m, int i);
void	txtrs_array(s_main	*m);
void	ft_errorr(char *s);
void	ft_free(char **s);


int	skip_spaces(char *s, int index);
int	check_path(char **s, int ch);
int	check_path(char **s, int ch);
int	is_valid_line(char *line);
int	count_map_lines(int fd);
int	valid_line(char *line);
int	ft_count(char	*s1);

char	*skip_s(char *s);

t_check	initialize_check(void);


#endif
