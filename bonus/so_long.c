/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabdessm <mabdessm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 16:42:23 by mabdessm          #+#    #+#             */
/*   Updated: 2024/09/02 23:10:49 by mabdessm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

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
		destroy_images(data);
		ft_free_tab(data->map);
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
	data->enemies = 0;
	while (data->map[++i])
	{
		j = -1;
		while (data->map[i][++j])
		{
			if (data->map[i][j] == 'C')
				++(data->total_cats);
			if (data->map[i][j] == 'F')
				++(data->enemies);
		}
	}
	data->height = i;
	data->width = j;
	data->exit = 0;
	data->fire_animation = 0;
	data->enemy_direction = 0;
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
