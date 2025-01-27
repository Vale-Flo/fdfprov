/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vflores <vflores@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 18:59:02 by vflores           #+#    #+#             */
/*   Updated: 2025/01/24 17:41:38 by vflores          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

// funcion para conectar puntos adyacentes en el mapa 3D
// verifica si el punto actual se encuentra en la ultima fila o colunma
// si no, conecta los puntos con una linea
void	connect_points(t_env *env,t_vector3 v)
{
	if (v.x != env->map.w - 1 && v.y != env->map.h - 1) // ultimos puntos en w y h (ultima fila(v.y) y columna(v.x))
	{
		ft_connect(env, v.z, (v.x + 1) + v.y * env->map.w, env->final_points);
		ft_connect(env, v.z, v.x + (v.y + 1) * env->map.w, env->final_points);
	}
	if (v.x == env->map.w - 1 && v.y != env->map.h - 1) // ultimos puntos en h
		ft_connect(env, v.z, v.x + (v.y + 1) * env->map.w, env->final_points);
	if (v.x != env->map.w - 1 && v.y == env->map.h - 1) // ultimos puntos en w
		ft_connect(env, v.z, (v.x + 1) + v.y * env->map.w, env->final_points);
}

// Funcion para determinar los limites en el mapa 3D
// Calcula las coordenadas de los puntos mas grandes y mas pequenios
// del mapa en la ventana grafica.
// Si los puntos estan fuera de la ventana grafica, se dibujan las flechas
// que indican la direccion en la que se encuentran los puntos fuera de la ventana.
void	limits(t_env *env)
{
	env->bg_x = env->final_points[(env->map.w - 1) + 0 * env->map.w].x;
	env->sm_x = env->final_points[0 +(env->map.h - 1) * env->map.w].x;
	env->bg_y = env->final_points[(env->map.w - 1) * (env->map.h - 1) + env->map.h - 1].y;
	env->sm_y = env->final_points[0].y;

	if (env->sm_x > WIN_W)
		draw_arrow_right(env);
	if (env->bg_x < 0)
		draw_arrow_left(env);
	if (env->sm_y > WIN_H)
		draw_arrow_down(env);
	if (env->bg_y < 0)
		draw_arrow_up(env);
}
