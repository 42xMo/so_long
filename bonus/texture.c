/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabdessm <mabdessm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 15:34:16 by mabdessm          #+#    #+#             */
/*   Updated: 2024/09/02 19:53:34 by mabdessm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

int	draw_textures(t_data *data)
{
	int	i;
	int	x;
	int	y;
	int	ii;

	mlx_get_screen_size(data->mlx_ptr, &x, &y);
	x /= data->textures.width;
	y /= data->textures.height;
	i = get_player_j_pos(data) - ((y / 2) - 1) - 1;
	while ((i + y) > data->height)
		--i;
	if (i < 0)
		i = -1;
	ii = 0;
	while (data->map[++i])
	{
		draw_textures2(data, i, x, ii);
		++ii;
	}
	return (0);
}

void	render_textures(t_data *data)
{
	data->win_ptr = mlx_new_window(data->mlx_ptr, (data->width
				* data->textures.width), (data->height * data->textures.height),
			"so_long");
	if (!data->win_ptr)
	{
		free(data->mlx_ptr);
		return ;
	}
	mlx_loop_hook(data->mlx_ptr, &draw_textures, data);
	mlx_hook(data->win_ptr, KeyRelease, KeyReleaseMask, &on_keypress, data);
	mlx_hook(data->win_ptr, DestroyNotify, StructureNotifyMask, &on_destroy,
		data);
	mlx_loop(data->mlx_ptr);
	on_destroy(data);
}

void	load_collectibles(t_data *data, int h, int w)
{
	data->textures.collectible1_texture = mlx_xpm_file_to_image(data->mlx_ptr,
			"./textures/cat_1.xpm", &h, &w);
	data->textures.collectible2_texture = mlx_xpm_file_to_image(data->mlx_ptr,
			"./textures/cat_2.xpm", &h, &w);
	data->textures.collectible3_texture = mlx_xpm_file_to_image(data->mlx_ptr,
			"./textures/cat_3.xpm", &h, &w);
	data->textures.collectible4_texture = mlx_xpm_file_to_image(data->mlx_ptr,
			"./textures/cat_4.xpm", &h, &w);
	data->textures.collectible5_texture = mlx_xpm_file_to_image(data->mlx_ptr,
			"./textures/cat_5.xpm", &h, &w);
	data->textures.collectible6_texture = mlx_xpm_file_to_image(data->mlx_ptr,
			"./textures/cat_6.xpm", &h, &w);
	data->textures.collectible7_texture = mlx_xpm_file_to_image(data->mlx_ptr,
			"./textures/cat_7.xpm", &h, &w);
	data->textures.collectible8_texture = mlx_xpm_file_to_image(data->mlx_ptr,
			"./textures/cat_shiny.xpm", &h, &w);
}

void	load_enemies(t_data *data, int h, int w)
{
	data->textures.enemy1_texture = mlx_xpm_file_to_image(data->mlx_ptr,
			"./textures/fire_1.xpm", &h, &w);
	data->textures.enemy2_texture = mlx_xpm_file_to_image(data->mlx_ptr,
			"./textures/fire_2.xpm", &h, &w);
	data->textures.enemy3_texture = mlx_xpm_file_to_image(data->mlx_ptr,
			"./textures/fire_3.xpm", &h, &w);
	data->textures.enemy4_texture = mlx_xpm_file_to_image(data->mlx_ptr,
			"./textures/fire_4.xpm", &h, &w);
	data->textures.enemy5_texture = mlx_xpm_file_to_image(data->mlx_ptr,
			"./textures/fire_5.xpm", &h, &w);
	data->textures.enemy6_texture = mlx_xpm_file_to_image(data->mlx_ptr,
			"./textures/fire_6.xpm", &h, &w);
}

void	load_textures(t_data *data)
{
	int	h;
	int	w;

	h = 80;
	w = 80;
	data->textures.height = h;
	data->textures.width = w;
	load_collectibles(data, h, w);
	load_enemies(data, h, w);
	data->textures.floor_texture = mlx_xpm_file_to_image(data->mlx_ptr,
			"./textures/floor.xpm", &h, &w);
	data->textures.wall_texture = mlx_xpm_file_to_image(data->mlx_ptr,
			"./textures/wall.xpm", &h, &w);
	data->textures.player_texture = mlx_xpm_file_to_image(data->mlx_ptr,
			"./textures/gab.xpm", &h, &w);
	data->textures.exit_texture = mlx_xpm_file_to_image(data->mlx_ptr,
			"./textures/exit_closed.xpm", &h, &w);
}
