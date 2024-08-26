/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabdessm <mabdessm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 16:42:23 by mabdessm          #+#    #+#             */
/*   Updated: 2024/08/26 17:36:50 by mabdessm         ###   ########.fr       */
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
	if (data->map)
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

int	draw_textures(t_data *data)
{
	int	i;
	int	j;

	i = -1;
	while (data->map[++i])
	{
		j = -1;
		while (data->map[i][++j])
		{
			if (data->map[i][j] == '1')
			{
				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
					data->textures.wall_texture, data->textures.width * j,
					data->textures.height * i);
			}
			if (data->map[i][j] == '0')
			{
				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
					data->textures.floor_texture, data->textures.width * j,
					data->textures.height * i);
			}
			if (data->map[i][j] == 'P')
			{
				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
					data->textures.player_texture, data->textures.width * j,
					data->textures.height * i);
			}
			if (data->map[i][j] == 'C')
			{
				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
					data->textures.collectible_texture, data->textures.width * j,
					data->textures.height * i);
			}
			if (data->map[i][j] == 'E')
			{
				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
					data->textures.exit_texture, data->textures.width * j,
					data->textures.height * i);
			}
		}
	}
	return (0);
}

void	render_textures(t_data *data)
{
	data->win_ptr = mlx_new_window(data->mlx_ptr,
					 (data->width * data->textures.width),
					 (data->height * data->textures.height), "so_long");
	if (!data->win_ptr)
	{
		free(data->mlx_ptr);
		return ;
	}
	mlx_loop_hook(data->mlx_ptr, &draw_textures, data);
	mlx_hook(data->win_ptr, KeyRelease, KeyReleaseMask, &on_keypress, data);
	mlx_hook(data->win_ptr, DestroyNotify, StructureNotifyMask, &on_destroy, data);
	mlx_loop(data->mlx_ptr);
	on_destroy(data);
}

void	load_textures(t_data *data)
{
	int	h;
	int	w;
	
	h = 80;
	w = 80;
	data->textures.height = h;
	data->textures.width = w;
	data->textures.floor_texture = mlx_xpm_file_to_image(data->mlx_ptr,
									 "./textures/floor.xpm", &h, &w);
	data->textures.wall_texture = mlx_xpm_file_to_image(data->mlx_ptr,
									 "./textures/wall.xpm", &h, &w);
	data->textures.player_texture = mlx_xpm_file_to_image(data->mlx_ptr,
									 "./textures/player.xpm", &h, &w);
	data->textures.collectible_texture = mlx_xpm_file_to_image(data->mlx_ptr,
									 "./textures/collectible.xpm", &h, &w);
	data->textures.exit_texture = mlx_xpm_file_to_image(data->mlx_ptr,
									 "./textures/exit.xpm", &h, &w);
}

void	assign_size(t_data *data)
{
	int	i;
	int	j;

	i = -1;
	while (data->map[++i])
	{
		j = 0;
		while (data->map[i][j])
			++j;
	}
	data->height = i;
	data->width = j;
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
		assign_size(&data);
		draw_map(data.map);
		load_textures(&data);
		render_textures(&data); 
	}
	else
		return (!return_error("Invalid number of arguments!"));
}
