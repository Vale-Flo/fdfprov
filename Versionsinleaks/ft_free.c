#include "fdf.h"

void	free_i_grid(t_env *env)
{
	size_t	y;

	y = 0;
	while (y < env->map.h)
		free(env->map.i_grid[y++]);
	free(env->map.i_grid);
}

void	ft_free_all(t_env *env)
{
	// ft_destroy_images(env);
	if (env->map.i_grid)
		free_i_grid(env);
	free(env->points);
	free(env->rotated);
	free(env->final_points);
	if(env->img)
		mlx_destroy_image(env->mlx, env->img);
	if(env->win)
		mlx_destroy_window(env->mlx, env->win);
	if(env->mlx)
	{
		mlx_destroy_display(env->mlx);
		free(env->mlx);
	}
}
