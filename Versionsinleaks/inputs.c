/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inputs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vflores <vflores@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 17:48:56 by vflores           #+#    #+#             */
/*   Updated: 2025/01/27 11:38:06 by vflores          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	key_handler(int keysym, t_env *env)
{
	if (keysym == KEY_ESC || keysym == KEY_Q) //ESC
		close_window(env);
	else if (keysym == KEY_A || keysym == KEY_LEFT) // LEFT (A / ARROW_LEFT)
		env->offset.x -= 10; // we are moving the point -10 in x
	else if (keysym == KEY_D || keysym == KEY_RIGHT) // RIGHT (D / ARROW_RIGHT)
		env->offset.x += 10; // we are moving the point +10 in x
	else if (keysym == KEY_S || keysym == KEY_DOWN) // DOWN (S / ARROW_DOWN)
		env->offset.y += 10; // we are moving the point +10 in y
	else if (keysym == KEY_W || keysym == KEY_UP) // UP (W / ARROW_UP)
		env->offset.y -= 10; // we are moving the point -10 in y
	else
		ft_printf("%d\n", keysym);
	return (0);
}

// int	mouse_handler(int mousecode, int x, int y, t_env *env)
// {
// 	/* x and y parameters are the pixel coordinates of the mouse
//     * in the window when the event was emitted
//     * you can use them to check that the user clicked in a specific region
//     * of the window
//     */
// 	(void) x;
// 	(void) y;
// 	if (mousecode == 4 && env->scale - 1 > 0) // Scroll UP && scale diminue jusqu'au minimum
// 		env->scale--;
// 	else if (mousecode == 5) // Scroll DOWN, on augmente le scale
// 		env->scale++;
// 	return (0);
// }

#include "fdf.h" // Asegúrate de incluir tu archivo de cabecera

// Función para manejar eventos de mouse
int	mouse_handler(int mousecode, int x, int y, t_env *env)
{
	// ft_printf("mouse: %i\n", mousecode);
	// Ignora las coordenadas del mouse si no las necesitas
	(void)x;
	(void)y;

	// Verifica el código del evento del mouse
	if (mousecode == 4) // Scroll hacia arriba
		env->scale++; // Aumenta la escala
	else if (mousecode == 5 && env->scale > 1) // Scroll hacia abajo
		env->scale--; // Disminuye la escala si es mayor a 1
	return (0); // Retorna 0 para indicar que se manejó correctamente
}
