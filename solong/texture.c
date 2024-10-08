/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabdessm <mabdessm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 15:34:16 by mabdessm          #+#    #+#             */
/*   Updated: 2024/09/02 17:07:09 by mabdessm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	draw_textures2(t_data *data, int i, int x, int ii)
{
	int	jj;
	int	j;

	jj = 0;
	j = get_player_i_pos(data) - ((x / 2) - 1) - 1;
	while ((j + x + 1) > data->width)
		--j;
	if (j < 0)
		j = -1;
	while (data->map[i][++j])
	{
		if (data->map[i][j] == '1')
			put_image(data, data->textures.wall_texture, ii, jj);
		if (data->map[i][j] == '0')
			put_image(data, data->textures.floor_texture, ii, jj);
		if (data->map[i][j] == 'P')
			put_image(data, data->textures.player_texture, ii, jj);
		data->cat_color = i * j;
		if (data->map[i][j] == 'C')
			draw_collectibles(data, ii, jj);
		if (data->map[i][j] == 'E')
			put_image(data, data->textures.exit_texture, ii, jj);
		++jj;
	}
}

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

void	load_textures(t_data *data)
{
	int	h;
	int	w;

	h = 80;
	w = 80;
	data->textures.height = h;
	data->textures.width = w;
	load_collectibles(data, h, w);
	data->textures.floor_texture = mlx_xpm_file_to_image(data->mlx_ptr,
			"./textures/floor.xpm", &h, &w);
	data->textures.wall_texture = mlx_xpm_file_to_image(data->mlx_ptr,
			"./textures/wall.xpm", &h, &w);
	data->textures.player_texture = mlx_xpm_file_to_image(data->mlx_ptr,
			"./textures/player.xpm", &h, &w);
	data->textures.exit_texture = mlx_xpm_file_to_image(data->mlx_ptr,
			"./textures/exit_closed.xpm", &h, &w);
}
