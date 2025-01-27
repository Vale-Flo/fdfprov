/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arrows.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vflores <vflores@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 18:27:19 by vflores           #+#    #+#             */
/*   Updated: 2025/01/17 18:58:21 by vflores          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

// se dibujan flechas en los 4 sentidos en una posicion especifica
// white color
void	draw_arrow_left(t_env *env)
{
	ft_draw_line(env, (t_vector2){20, WIN_H / 2}, \
							(t_vector2){40, WIN_H / 2 - 20}, 0xFFFFFFFF);
	ft_draw_line(env, (t_vector2){20, WIN_H / 2}, \
							(t_vector2){40, WIN_H / 2 + 20}, 0xFFFFFFFF);
}

void	draw_arrow_right(t_env *env)
{
	ft_draw_line(env, (t_vector2){WIN_W - 20, WIN_H / 2}, \
						(t_vector2){WIN_W - 40, WIN_H / 2 - 20}, 0xFFFFFFFF);
	ft_draw_line(env, (t_vector2){WIN_W - 20, WIN_H / 2}, \
						(t_vector2){WIN_W - 40, WIN_H / 2 + 20}, 0xFFFFFFFF);
}

void	draw_arrow_up(t_env *env)
{
	ft_draw_line(env, (t_vector2){WIN_W / 2, 20}, \
								(t_vector2){WIN_W / 2 - 20, 40}, 0xFFFFFFFF);
	ft_draw_line(env, (t_vector2){WIN_W / 2, 20}, \
								(t_vector2){WIN_W / 2 + 20, 40}, 0xFFFFFFFF);
}

void	draw_arrow_down(t_env *env)
{
	ft_draw_line(env, (t_vector2){WIN_W / 2, WIN_H - 20}, \
					(t_vector2){WIN_W / 2 - 20, WIN_H - 40}, 0xFFFFFFFF);
	ft_draw_line(env, (t_vector2){WIN_W / 2, WIN_H - 20}, \
					(t_vector2){WIN_W / 2 + 20, WIN_H - 40}, 0xFFFFFFFF);
}
