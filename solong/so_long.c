/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabdessm <mabdessm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 16:42:23 by mabdessm          #+#    #+#             */
/*   Updated: 2024/08/23 17:03:54 by mabdessm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

//for testing
void	draw_map(char **map)
{
	int	i;

	i = -1;
	while (map && map[++i])
		ft_printf("%s\n", map[i]);
}

int	on_destroy(t_data *data)
{
	ft_free_tab(data->map);
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

void	render_textures(t_data *data)
{
	data->win_ptr = mlx_new_window(data->mlx_ptr, 600, 400, "so_long");
	if (!data->win_ptr)
	{
		free(data->mlx_ptr);
		return ;
	}
	//mlx_loop_hook(data->mlx_ptr, /*&the function that renders textures*/, data);
	mlx_hook(data->win_ptr, KeyRelease, KeyReleaseMask, &on_keypress, data);
	mlx_hook(data->win_ptr, DestroyNotify, StructureNotifyMask, &on_destroy, data);
	mlx_loop(data->mlx_ptr);
	on_destroy(data);
}

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc == 2)
	{
		data.steps = 0;
		data.mlx_ptr = mlx_init();
		data.map = check_errors(argv[1]);
		if (!data.map)
			on_destroy(&data);
		draw_map(data.map);
		//load_textures(data);
		//store the images in data using the mlx_xpm_file_to_image function
		//have a new content in data that is a struct itself called textures
		//that has all the images for the textures then use that in the
		//function that renders everything
		render_textures(&data); 
	}
	else
		return (!return_error("Invalid number of arguments!"));
}
