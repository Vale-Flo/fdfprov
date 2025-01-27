/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vflores <vflores@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 18:06:54 by vflores           #+#    #+#             */
/*   Updated: 2025/01/27 16:34:25 by vflores          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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

//El operador -> se usa porque p es un puntero y
//necesitas "desreferenciarlo" para acceder a los miembros.

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
	// close(fd);
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
			env->points[i++] = (t_vector3){x, y, env->map.i_grid[y][x]};
			x++;
		}
		x = 0;
		y++;
	}
}

//Resultado: Un array de puntos 3D (env->points) listo
//para ser usado en operaciones gráficas como transformaciones y proyecciones.
