/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabdessm <mabdessm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 19:55:25 by mabdessm          #+#    #+#             */
/*   Updated: 2024/09/02 23:28:37 by mabdessm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

void	draw_enemies(t_data *data, int i, int j, int k)
{
	if (k % 6 == 0)
		put_image(data, data->textures.enemy1_texture, i, j);
	else if (k % 6 == 1)
		put_image(data, data->textures.enemy2_texture, i, j);
	else if (k % 6 == 2)
		put_image(data, data->textures.enemy3_texture, i, j);
	else if (k % 6 == 3)
		put_image(data, data->textures.enemy4_texture, i, j);
	else if (k % 6 == 4)
		put_image(data, data->textures.enemy5_texture, i, j);
	else if (k % 6 == 5)
		put_image(data, data->textures.enemy6_texture, i, j);
	usleep(10000);
}

void	draw_collectibles(t_data *data, int i, int j)
{
	if (data->cat_color % 8 == 0)
		put_image(data, data->textures.collectible1_texture, i, j);
	else if (data->cat_color % 8 == 1)
		put_image(data, data->textures.collectible2_texture, i, j);
	else if (data->cat_color % 8 == 2)
		put_image(data, data->textures.collectible3_texture, i, j);
	else if (data->cat_color % 8 == 3)
		put_image(data, data->textures.collectible4_texture, i, j);
	else if (data->cat_color % 8 == 4)
		put_image(data, data->textures.collectible5_texture, i, j);
	else if (data->cat_color % 8 == 5)
		put_image(data, data->textures.collectible6_texture, i, j);
	else if (data->cat_color % 8 == 6)
		put_image(data, data->textures.collectible7_texture, i, j);
	else if (data->cat_color % 8 == 7)
		put_image(data, data->textures.collectible8_texture, i, j);
}

void	move_enemies(t_data *data, int i, int j, int k)
{
	if (k % 50 == 0)
	{
		if (!data->enemy_direction && data->map[i - 1][j] == '0')
		{
			data->map[i][j] = '0';
			data->map[i - 1][j] = 'F';
		}
		else
			data->enemy_direction = 1;
		if (data->enemy_direction && data->map[i + 1][j] == '0')
		{
			data->map[i][j] = '0';
			data->map[i + 1][j] = 'F';
		}
		else
			data->enemy_direction = 0;
	}
}

int	assign_j(t_data *data, int x)
{
	int	j;

	j = get_player_i_pos(data) - ((x / 2) - 1) - 1;
	while ((j + x + 1) > data->width)
		--j;
	if (j < 0)
		j = -1;
	return (j);
}

void	draw_textures2(t_data *data, int i, int x, int ii)
{
	int	jj;
	int	j;

	jj = 0;
	j = assign_j(data, x);
	while (data->map[i][++j])
	{
		if (data->map[i][j] == '1')
			put_image(data, data->textures.wall_texture, ii, jj++);
		if (data->map[i][j] == '0')
			put_image(data, data->textures.floor_texture, ii, jj++);
		if (data->map[i][j] == 'P')
			put_image(data, data->textures.player_texture, ii, jj++);
		data->cat_color = i * j;
		if (data->map[i][j] == 'C')
			draw_collectibles(data, ii, jj++);
		if (data->map[i][j] == 'E')
			put_image(data, data->textures.exit_texture, ii, jj++);
		if (data->map[i][j] == 'F')
		{
			draw_enemies(data, ii, jj++, data->fire_animation++);
			move_enemies(data, i, j, data->fire_animation);
		}
	}
}
