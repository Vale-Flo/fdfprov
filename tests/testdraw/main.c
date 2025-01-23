/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vflores <vflores@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 14:02:38 by vflores           #+#    #+#             */
/*   Updated: 2025/01/16 17:54:33 by vflores          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

//struct env (structure t_env *env) is the variable
//then in the struct we have the variable map, this is also an struct
// whose varible is path
//So we can open the path of the map from the struct env
void	parse_map_info(t_env *env)
{
	int		fd;
	char	*line;
	char	**f_line;

	fd = open(env->map.path, O_RDONLY);
	if (fd < 0) //verificar que el archivo se pueda abrir
		map_error("Map not found.");
	//h y w en 0 para inicializar
	env->map.h = 0;
	env->map.w = 0;
	// leemos la primer linea del documento ?
	line = get_next_line(fd);
	// cada punto es un numero y estan separados por espacios
	// entonces queremos recuperar los puntos(del line) en un tableau de tableaux
	// cada punto es un "elemento" en nuestro gran tableau de tableaux (f_line)
	f_line = ft_split(line, ' ');
	//vamos recorriendo el tableau de tableaux con el w del map, se aumenta 1 a 1
	//hasta terminar de recorrer el w, o sea llegamos al maximo width
	while (f_line[env->map.w])
		env->map.w++;
	//vamos recorriendo el tableau de tableaux con el h del map, se aumenta 1 a 1
	//hasta terminar de recorrer el h, o sea llegamos al maximo heigth
	// Para esto primero hay q leer el documento linea por linea mientras exista la linea (line)
	while (line)
	{
		env->map.h++;
		free(line); //liberamos la linea a cada paso
		line = get_next_line(fd);
	}
	int i;
	i = 0;
	while (f_line[i])
		free(f_line[i++]); //liberamos los elementos de f_line a cada paso (cada uno de los tableaux)
	free(f_line); //tmb liberamos el f_line, porque se hizo malloc del tableau de tableaux
	close(fd);
}


int	main(int ac, char **av)
{
	t_env	env;
	(void)ac;
	env.scale = 35;
	env.alpha = 0.5;
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
	parse_map_info(&env);
	printf("heigth: %zu\n", env.map.h);
	printf("width: %zu\n", env.map.w);
	env.mlx = mlx_init();
	env.win = mlx_new_window(env.mlx, WIN_W, WIN_H, WIN_NAME);
	env.img = mlx_new_image(env.mlx, WIN_W, WIN_H);
	env.addr = mlx_get_data_addr(env.img, &env.bits_per_pixel, &env.line_length, &env.endian);
	/*
	** After creating an image, we can call `mlx_get_data_addr`, we pass
	** `bits_per_pixel`, `line_length`, and `endian` by reference. These will
	** then be set accordingly for the *current* data address.
	*/
	/* end of MLX initialisation */
    /* Here I will be declaring the hooks, see below for their implementation.
    */

	mlx_hook(env.win, 4, 0, mouse_handler, &env);
	// mouse_handler will be called everytime a mouse down event is emitted
	mlx_hook(env.win, 2, 1L << 0, key_handler, &env);
	// key_handler will be called everytime a key is pressed (KeyPressMask)
	mlx_hook(env.win, 17, 1L << 0, close_window, &env);
	// close_window is called when we click on the red cross to close the window (KeyPressMask)
	mlx_loop_hook(env.mlx, render, &env);
	// Since MXL loops over and over again, we can use the mlx_loop_hook
    // to execute a function everytime MLX loops over.
	mlx_loop(env.mlx);
	return (0);
}

// int	render(t_env *env)
// {
// 	size_t	x;
// 	size_t	y;
// 	size_t	i;

// 	draw_background(env);
// 	rotate_points(env);
// 	scale_points(env, env->scale);
// 	translate_points(env);
// 	limits(env);
// 	x = 0;
// 	y = 0;
// 	while (y < env->map.h)
// 	{
// 		while (x < env->map.w)
// 		{
// 			i = x + y * env->map.w;
// 			connect_points(env, (t_vector3){x, y, i});
// 			x++;
// 		}
// 		x = 0;
// 		y++;
// 	}
// 	mlx_put_image_to_window(env->mlx, env->win, env->img, 0, 0);
// 	return (0);
// }
