/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vflores <vflores@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 14:02:38 by vflores           #+#    #+#             */
/*   Updated: 2025/01/15 17:58:25 by vflores          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

//struct env (structure t_env *env) is the variable
//then in the struct we have the variable map, this is also an struct
// whose varible is path
//So we can open the path of the map from the struct env

void free_split(char ***split)
{
	int i;

	i = 0;
	while ((*split)[i])
	{
		free((*split)[i]);
		i++;
	}
	free(*split);
}

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
	free_split(&f_line);

	// int i;
	// i = 0;
	// while (f_line[i])
	// 	free(f_line[i++]); //liberamos los elementos de f_line a cada paso (cada uno de los tableaux)
	// free(f_line); //tmb liberamos el f_line, porque se hizo malloc del tableau de tableaux
	// close(fd);
}



void	parse_map(t_env *env)
{
	int		fd;
	char	*line;
	char	**f_line;
	t_stvector2	v; //se define variablel v (vector) tipo estructura stvector2
	// se podria definir tmb como t_stvector2 v = {0, 0};

	//los vectores los inicializamos en el centro de coordenadas
	// El operador . (punto) se utiliza para acceder a los miembros de la estructura.
	v.x = 0;
	v.y = 0;
	//v.y controla las filas del mapa (env->map.h).
	//v.x controla las columnas del mapa (env->map.w).
	fd = open(env->map.path, O_RDONLY);
	if (fd < 0) //verificar que el archivo se pueda abrir
		map_error("Map not found.");
	// (Reservar memoria para la matriz)
	//Se reserva un array de punteros de tamaño igual al número de filas (env->map.h).
	env->map.i_grid = malloc(env->map.h * sizeof(int *));
	if (!env->map.i_grid)
		map_error("Error allocating memory.");
	//recorremos la altura(h) del mapa con el vector y(v.y)
	while (v.y < env->map.h)
	{
		// Se reserva memoria para cada fila:
		env->map.i_grid[v.y] = malloc(env->map.w * sizeof(int));
		if (!env->map.i_grid[v.y])
			map_error("Error allocating memory.");
		line = get_next_line(fd);
		f_line = ft_split(line, ' ');
		free(line);

		while (v.x < env->map.w)
		{
			// Cada palabra se convierte en un entero y se guarda en la matriz:
			env->map.i_grid[v.y][v.x] = ft_atoi(f_line[v.x]);
			v.x++;
		}
		v.x = 0;
		v.y++;

		free_split(&f_line);

		// int i;
		// i = 0;
		// while (f_line[i])
			// free(f_line[i++]); //liberamos los elementos de f_line a cada paso (cada uno de los tableaux)
		// free(f_line); //tmb liberamos el f_line, porque se hizo malloc del tableau de tableaux
	}
	close(fd);
}
// Resultado: Se llena env->map.i_grid, que contiene las alturas del mapa como una matriz de enteros.


void	fill_points_vector(t_env *env)
{
	size_t	x;
	size_t	y;
	size_t	i;

	// Se reserva memoria para un array de estructuras t_vector3, que representan puntos en 3D
	env->points = malloc(env->map.h * env->map.w * sizeof(t_vector3));
	if (!env->points)
		map_error("Error allocating memory.");
	x = 0;
	y = 0;
	i = 0;
	// z es el valor en env->map.i_grid[y][x].
	while(y < env->map.h)
	{
		while(x < env->map.w)
		{
			//Para cada par (x, y), se crea una instancia de t_vector3 con los valores x, y, alturas del map.i_grid
			env->points[i++] = (t_vector3){x, y, env->map.i_grid[y][x]};
			x++;
		}
		x = 0;
		y++;
	}
}



int	main(int ac, char **av)
{
	t_env	env;
	(void)ac;
	// env.scale = 35;
	// env.alpha = 0.5;
	// if (ac == 3)
	// 	env.scale = ft_atoi(av[2]);
	// else if (ac > 3 || ac == 1)
	// {
	// 	ft_printf("No map specified.\n");
	// 	exit(1);
	// }
	env.map.path = av[1];
	parse_map_info(&env);
	printf("heigth: %zu\n", env.map.h);
	printf("width: %zu\n", env.map.w);
	parse_map(&env);
	size_t y = 0;
	size_t x;
	printf("Contenido del mapa:\n");
	while (y < env.map.h)
	{
		x = 0;
		while (x < env.map.w)
		{
			printf("%d ", env.map.i_grid[y][x]);
			x++;
		}
		printf("\n");
		y++;
	}
	fill_points_vector(&env);
	// size_t i = 0;
	// printf("Contenido del vector:\n");
	// while (i < env.map.w * env.map.h)
	// {
	// 	printf("Point %zu: x=%.1f, y=%.1f, z=%.1f\n",
	// 		i, env.points[i].x, env.points[i].y, env.points[i].z);
	// 	i++;
	// }

	y=0;
	while (y < env.map.h)
	{
		free(env.map.i_grid[y]);
		y++;
	}
	free(env.map.i_grid);

	free(env.points);
	// y = 0;
	// while (y < env.map.h)
	// {
	// 	x = 0;
	// 	while(x < env.map.w)
	// 	{
	// 		free(env.points[y][x]);
	// 		x++;
	// 	}
	// 	// x = 0;
	// 	free(env.points[y]);
	// 	y++;
	// }
	// free(env.points);

	// env.mlx = mlx_init();
	// env.win = mlx_new_window(env.mlx, WIN_W, WIN_H, WIN_NAME);
	// env.img = mlx_new_image(env.mlx, WIN_W, WIN_H);
	// env.addr = mlx_get_data_addr(env.img, &env.bits_per_pixel, &env.line_length, &env.endian);

	// mlx_hook(env.win, 4, 0, mouse_handler, &env);
	// mlx_hook(env.win, 2, 1L << 0, key_handler, &env);
	// mlx_hook(env.win, 17, 1L << 0, close_window, &env);
	// mlx_loop_hook(env.mlx, render, &env);
	// mlx_loop(env.mlx);
	return (0);
}

// int key_handler(int keycode, t_env *env)
// {
//     if (keycode == 53)
//         ft_printf("ESCAPE");
//     else if (keycode == 0 || keycode == 123)
//         ft_printf("LEFT (A / ARROW_LEFT)");
//     else if (keycode == 2 || keycode == 124)
//         ft_printf("RIGHT (D / ARROW_RIGHT)");
//     else if (keycode == 1 || keycode == 125)
//         ft_printf("DOWN (S / ARROW_DOWN)");
//     else if (keycode == 13 || keycode == 126)
//         ft_printf("LEFT (A / ARROW_LEFT)");
//     else
//         ft_printf("%d\n", keycode);
//     return (0);
// }


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
