/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vflores <vflores@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 18:24:02 by vflores           #+#    #+#             */
/*   Updated: 2025/01/27 16:22:42 by vflores          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# define WIN_W 1280
# define WIN_H 720
# define WIN_NAME "fdf"

# define KEY_W 119
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100

# define KEY_UP 65362
# define KEY_DOWN 65364
# define KEY_LEFT 65361
# define KEY_RIGHT 65363

# define KEY_ESC 65307
# define KEY_Q 113

// #ifndef ALPHA
// # define env.alpha = 0.5
// # endif
# include <fcntl.h>
# include <math.h>
# include <stdio.h>
# include <X11/X.h>
# include "libft.h"
# include "mlx.h"
# include "fdf_structures.h"

// main.c
int		render(t_env *env);

// inputs.c
int		key_handler(int keycode, t_env *env);
int		mouse_handler(int mousecode, int x, int y, t_env *env);

// utils.c
int		close_window(t_env *env);
void	map_error(char *s);
void	init_map(t_env *env);

// draw.c
void	ft_put_pixel(t_env *env, t_vector2 v, int color);
void	ft_draw_line(t_env *env, t_vector2 s, t_vector2 e, int col);
void	ft_draw_point(t_env *env, t_vector2 p, int col, int sw);
void	draw_background(t_env *env);
void	ft_connect(t_env *env, int i, int j, t_vector2 *points);

// arrows.c
void	draw_arrow_left(t_env *env);
void	draw_arrow_right(t_env *env);
void	draw_arrow_up(t_env *env);
void	draw_arrow_down(t_env *env);

// map_parser.c
void free_split(char ***split);
void	parse_map_info(t_env *env);
void	parse_map(t_env *env);
void	fill_points_vector(t_env *env);

// free.c
void	free_i_grid(t_env *env);
void	ft_free_all(t_env *env);

// points.c
void	rotate_points(t_env *env);
void	translate_points(t_env *env);
void	scale_points(t_env *env, int s);

// render_utils.c
void	connect_points(t_env *env, t_vector3 v);
void	limits(t_env *env);

#endif
