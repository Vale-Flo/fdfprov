/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vflores <vflores@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 13:44:34 by vflores           #+#    #+#             */
/*   Updated: 2025/01/27 17:31:06 by vflores          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	map_error(char *s)
{
	ft_printf("%s\n", s);
	exit(1);
}

int	close_window(t_env *env)
{
	ft_free_all(env);
	exit(0);
}

void	init_map(t_env *env)
{
	parse_map_info(env);
	parse_map(env);
	fill_points_vector(env);
	env->offset.x = 0;
	env->offset.y = 0;
	env->bg_x = 0;
	env->sm_x = WIN_W;
	env->bg_y = 0;
	env->sm_y = WIN_H;
}
