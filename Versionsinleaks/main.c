/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vflores <vflores@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 14:02:38 by vflores           #+#    #+#             */
/*   Updated: 2025/01/27 17:12:14 by vflores          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"



int	main(int ac, char **av)
{
	t_env	env;
	env.alpha = 0.5;
	env.scale = 35;
	if (ac == 3)
		env.scale = ft_atoi(av[2]);
	else if (ac > 3 || ac == 1)
	{
		ft_printf("No map specified.\n");
		exit(1);
	}
	/*
	* this is the MLX initialisation, I only put it in the example so you can
	* better see what I am doing below
	*/

	env.map.path = av[1];
	init_map(&env);
	env.rotated = malloc(env.map.h * env.map.w * sizeof(t_vector2));
	env.final_points = malloc(env.map.h * env.map.w * sizeof(t_vector2));
	// printf("heigth: %zu\n", env.map.h);
	// printf("width: %zu\n", env.map.w);*/
	//env.mlx = NULL;
	env.mlx = mlx_init();
	if (!env.mlx)
	{
		fprintf(stderr, "Error al inicializar MinilibX\n");
		fflush(stderr);
		return (1);
	}

	env.win = mlx_new_window(env.mlx, WIN_W, WIN_H, WIN_NAME);
	env.img = mlx_new_image(env.mlx, WIN_W, WIN_H);
	env.addr = mlx_get_data_addr(env.img, &env.bits_per_pixel, &env.line_length, &env.endian);
	// /*
	// ** After creating an image, we can call `mlx_get_data_addr`, we pass
	// ** `bits_per_pixel`, `line_length`, and `endian` by reference. These will
	// ** then be set accordingly for the *current* data address.
	// */
	// /* end of MLX initialisation */
    // /* Here I will be declaring the hooks, see below for their implementation.
    // */

	// mlx_hook(env.win, 4, 0, mouse_handler, &env);
	// mouse_handler will be called everytime a mouse down event is emitted
	mlx_hook(env.win, 2, 1L << 0, key_handler, &env);
	// key_handler will be called everytime a key is pressed (KeyPressMask)
	mlx_hook(env.win, 17, 1L << 0, close_window, &env);
	// close_window is called when we click on the red cross to close the window (KeyPressMask)

	mlx_hook(env.win, ButtonPress, ButtonReleaseMask, mouse_handler, &env);
	mlx_mouse_hook(env.win, mouse_handler, &env);

	mlx_loop_hook(env.mlx, render, &env);
	// Since MXL loops over and over again, we can use the mlx_loop_hook
    // to execute a function everytime MLX loops over.
	mlx_loop(env.mlx);
	ft_free_all(&env);
	return (0);
}

// renderizar mapa 3D
int	render(t_env *env)
{
	size_t	x;
	size_t	y;
	size_t	i;

	draw_background(env); //background
	rotate_points(env); // "rotate" points
	scale_points(env, env->scale); // scale points
	translate_points(env); // translate points
	limits(env); // we see which are the limits
	x = 0;
	y = 0;
	while (y < env->map.h) //iteramos filas
	{
		while (x < env->map.w) //iteramos columnas dentro de 1 fila
		{
			i = x + y * env->map.w; // calculamos la cantidad de puntos que hay en las filas anteriores
			// y = fila actual por el ancho de la matriz (env->map.w)
			// + x (la coordenada actual)
			// te da la coordenada del punto actual en el arreglo de puntos del mapa 3D de la ventana
			connect_points(env, (t_vector3){x, y, i});
			x++;
		}
		x = 0;
		y++;
	}
	mlx_put_image_to_window(env->mlx, env->win, env->img, 0, 0); // display the image
	return (0);
}
