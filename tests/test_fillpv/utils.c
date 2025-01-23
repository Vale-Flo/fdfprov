/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vflores <vflores@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 13:44:34 by vflores           #+#    #+#             */
/*   Updated: 2025/01/15 11:20:59 by vflores          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	map_error(char *s)
{
	ft_printf("%s\n", s);
	exit(1);
}

// int	close_window(t_env *env)
// {
// 	mlx_destroy_window(env->mlx, env->win);
// 	exit(0);
// }
