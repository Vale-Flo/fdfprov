/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   points.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vflores <vflores@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 11:41:51 by vflores           #+#    #+#             */
/*   Updated: 2025/01/27 17:02:35 by vflores          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

// alpha = angulo en radianes
// rotated, son los puntos luego de aplicar la proyeccion isometrica
// final points sont los puntos luego de aplicar la proyeccion isometrica.
void	rotate_points(t_env *env)
{
	size_t	i;
	// env->alpha = 0.5;

	i = 0;
	// env->rotated = malloc(env->map.h * env->map.w * sizeof(t_vector2));
	// if (!env->rotated)
	// 	map_error("Error allocating memory.");
	// env->final_points = malloc(env->map.h * env->map.w * sizeof(t_vector2));
	// if (!env->final_points)
	// 	map_error("Error allocating memory.");
	// while (i < env->map.h * env->map.w)
	// {
	// 	env->rotated[i].x = 0;
	// 	env->rotated[i].y = 0;
	// 	env->final_points[i].x = env->rotated[i].x;
	// 	env->final_points[i].y = env->rotated[i].y;
	// 	i++;
	// }
	while (i < env->map.h * env->map.w)
	{
		env->rotated[i].x = env->points[i].x * cosf(env->alpha) \
							+ env->points[i].y * cosf(env->alpha + 2) \
							+ env->points[i].z * cosf(env->alpha - 2);
		env->rotated[i].y = env->points[i].x * sinf(env->alpha) \
							+ env->points[i].y * sinf(env->alpha + 2) \
							+ env->points[i].z * sinf(env->alpha - 2);
		env->final_points[i].x = env->rotated[i].x;
		env->final_points[i].y = env->rotated[i].y;
		i++;
	}
//	free(env->rotated);
}

// esta funcion aplica una traslacion a los puntos en el espacio 2D
// para moverlos a una posicion especifica de la ventana, asi quedan con margen
// offset = vector de traslacion
// scale = vector de escala
void	translate_points(t_env *env)
{
	size_t	i;

	i = 0;
	while (i < env->map.h * env->map.w)
	{
		env->final_points[i].x += (WIN_W - (env->map.w / 2) * env->scale) / 2 \
														+ env->offset.x;
		env->final_points[i].y += (WIN_H - (env->map.h / 2) * env->scale) / 2 \
														+ env->offset.y;
		i++;
	}
}

//esta funcion sirve para cambiar la escala de los puntos
//el mapa puede ser enorme y asi se adapta
// s es el factor de escala
void	scale_points(t_env *env, int s)
{
	size_t	i;

	i = 0;
	while (i < env->map.h * env->map.w)
	{
		env->final_points[i].x *= s;
		env->final_points[i].y *= s;
		i++;
	}
}
