/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabdessm <mabdessm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 14:52:23 by mabdessm          #+#    #+#             */
/*   Updated: 2024/08/22 15:30:42 by mabdessm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

typedef struct s_data
{
	void	*mlx_ptr;
	void	*win_ptr;
	int		steps;
}	t_data;

int	on_destroy(t_data *data)
{
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	mlx_destroy_display(data->mlx_ptr);
	free(data->mlx_ptr);
	exit(0);
	return (0);
}

int	on_keypress(int keysym, t_data *data)
{
	if (keysym == 65307)
		on_destroy(data);
	if (keysym == 97 || keysym == 100 || keysym == 119 || keysym == 115)
	{
		//only do printf if the character actually moved so it shoudln't count
		//if the character is in collision with a wall even if key is pressed
		printf("Number of Steps : %d\n", ++(data->steps));
	}
	return (0);
}

int	main(void)
{
	t_data	data;

	data.steps = 0;
	data.mlx_ptr = mlx_init();
	if (!data.mlx_ptr)
		return (1);
	data.win_ptr = mlx_new_window(data.mlx_ptr, 600, 400, "so_long");
	if (!data.win_ptr)
		return (free(data.mlx_ptr), 1);

	// Register key release hook
	mlx_hook(data.win_ptr, KeyRelease, KeyReleaseMask, &on_keypress, &data);

	// Register destroy hook
	mlx_hook(data.win_ptr, DestroyNotify, StructureNotifyMask, &on_destroy, &data);

	// Generate Images
	//mlx_loop_hook(data.mlx_ptr, /*function that creates the images, background and animations (draws map)*/, &data);

	// Loop over the MLX pointer
	mlx_loop(data.mlx_ptr);
	return (0);
}
