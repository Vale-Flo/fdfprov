/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vflores <vflores@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 14:32:37 by vflores           #+#    #+#             */
/*   Updated: 2025/01/16 16:48:46 by vflores          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/* a simple function to put a pixel to the screen by its x and y coordinates */
void	ft_put_pixel(t_env *env, t_vector2 v, int color)
{
	char	*pxl;

	//las coord x e y entre 0 y su maximo en la ventana
	if (v.x >= 0 && v.x < WIN_W && v.y >= 0 && v.y < WIN_H)
	{
		pxl = env->addr + ((int)v.y * env->line_length \
									+ (int)v.x * (env->bits_per_pixel / 8));
		*(unsigned int *)pxl = color;
	}
}
/* Draw line: it is use to join all your points by lines */
//s = start
//e = end
void	ft_draw_line(t_env *env, t_vector2 s, t_vector2 e, int color)
{
	float		step;
	t_vector3	v;
	t_vector2	delta;

	delta.x = e.x - s.x;
	delta.y = e.y - s.y;
	// nuestro paso sera el mayor delta
	if (fabsf(delta.x) >= fabsf(delta.y)) //porq no usa abs???
		step = fabsf(delta.x);
	else
		step = fabsf(delta.y);
	delta.x = delta.x / step;
	delta.y = delta.y / step;
	v.x = s.x;
	v.y = s.y;
	v.z = 0;
	while (v.z < step)
	{
		ft_put_pixel(env, (t_vector2){v.x, v.y}, color);
		v.x = v.x + delta.x;
		v.y = v.y + delta.y;
		v.z++;
	}
}

/* we draw the points with the fonction (ft_put_pixel) */
// sw = ???????
//cuando usamos la funcion???
void	ft_draw_point(t_env *env, t_vector2 p, int color, int sw)
{
	size_t	y;
	size_t	x;

	y = p.y - sw;
	x = p.x - sw;
	while (y <= p.y + sw)
	{
		while (++x <= p.x + sw)
			ft_put_pixel(env, (t_vector2){x, y}, color);
		x = p.x - sw;
		y++;
	}
}
/* A function that makes a black bakcground with pixels */
void	draw_background(t_env *env)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i <= WIN_H)
	{
		while (j <= WIN_W)
		{
			ft_put_pixel(env, (t_vector2){j, i}, 0x000000); // black color
			j++;
		}
		j = 0;
		i++;
	}
}

/* We connect the points with a blue line */
void	connect(t_env *env, int i, int j, t_vector2 *points)
{
	ft_draw_line(env, points[i], points[j], 0xFFFFFFFF); // blue color
}
