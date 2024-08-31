/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabdessm <mabdessm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 16:42:23 by mabdessm          #+#    #+#             */
/*   Updated: 2024/08/31 03:39:07 by mabdessm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

// for testing
/*void	draw_map(char **map)
{
	int	i;

	i = -1;
	while (map && map[++i])
		ft_printf("%s\n", map[i]);
}*/

int	on_destroy(t_data *data)
{
	if (data->map)
	{
		ft_free_tab(data->map);
		mlx_destroy_image(data->mlx_ptr, data->textures.floor_texture);
		mlx_destroy_image(data->mlx_ptr, data->textures.wall_texture);
		mlx_destroy_image(data->mlx_ptr, data->textures.player_texture);
		mlx_destroy_image(data->mlx_ptr, data->textures.collectible1_texture);
		mlx_destroy_image(data->mlx_ptr, data->textures.collectible2_texture);
		mlx_destroy_image(data->mlx_ptr, data->textures.collectible3_texture);
		mlx_destroy_image(data->mlx_ptr, data->textures.collectible4_texture);
		mlx_destroy_image(data->mlx_ptr, data->textures.collectible5_texture);
		mlx_destroy_image(data->mlx_ptr, data->textures.collectible6_texture);
		mlx_destroy_image(data->mlx_ptr, data->textures.collectible7_texture);
		mlx_destroy_image(data->mlx_ptr, data->textures.collectible8_texture);
		mlx_destroy_image(data->mlx_ptr, data->textures.exit_texture);
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	}
	mlx_destroy_display(data->mlx_ptr);
	free(data->mlx_ptr);
	exit(0);
	return (0);
}

int	on_keypress(int keysym, t_data *data)
{
	if (keysym == 65307)
		on_destroy(data);
	if (keysym == 97)
		move_left(data);
	if (keysym == 100)
		move_right(data);
	if (keysym == 119)
		move_up(data);
	if (keysym == 115)
		move_down(data);
	return (0);
}

void	assign_size(t_data *data)
{
	int	i;
	int	j;

	i = -1;
	data->total_cats = 0;
	data->current_cats = 0;
	while (data->map[++i])
	{
		j = -1;
		while (data->map[i][++j])
		{
			if (data->map[i][j] == 'C')
				++(data->total_cats);
		}
	}
	data->height = i;
	data->width = j;
	data->exit = 0;
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
		load_textures(&data);
		render_textures(&data);
	}
	else
		return (!return_error("Invalid number of arguments!"));
}
