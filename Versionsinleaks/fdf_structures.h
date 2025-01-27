/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_structures.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vflores <vflores@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 18:17:09 by vflores           #+#    #+#             */
/*   Updated: 2025/01/23 16:55:55 by vflores          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_STRUCTURES_H
# define FDF_STRUCTURES_H

//Representa un punto en 3D
typedef struct s_vector3 {
	float	x;
	float	y;
	float	z;
}				t_vector3;

//Representa un punto en 2D (size_t)
typedef struct s_stvector2 {
	size_t	x;
	size_t	y;
}				t_stvector2;

//Representa un punto en 2D (float)
typedef struct s_vector2 {
	float	x;
	float	y;
}				t_vector2;

// h = heigth
// w = width
typedef struct s_map {
	char		*path;
	size_t		h;
	size_t		w;
	int			**i_grid;
}				t_map;

//env tiene struct dentro
typedef struct s_env {
	void		*mlx;
	void		*win;
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	int			scale;
	float		alpha;
	float		sm_y;
	float		bg_y;
	float		sm_x;
	float		bg_x;
	t_vector2	offset;
	t_map		map;
	t_vector3	*points;
	t_vector2	*final_points;
	t_vector2	*rotated;
}				t_env;

#endif
