/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_move_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabdessm <mabdessm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 15:28:47 by mabdessm          #+#    #+#             */
/*   Updated: 2024/08/31 04:48:58 by mabdessm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	get_player_i_pos(t_data *data)
{
	int	i;
	int	j;
	int	player_pos;

	i = -1;
	while ((data->map)[++i])
	{
		j = -1;
		while ((data->map)[i][++j])
		{
			if ((data->map)[i][j] == 'P')
				player_pos = j;
		}
	}
	return (player_pos);
}

int	get_player_j_pos(t_data *data)
{
	int	i;
	int	j;
	int	player_pos;

	i = -1;
	while ((data->map)[++i])
	{
		j = -1;
		while ((data->map)[i][++j])
		{
			if ((data->map)[i][j] == 'P')
				player_pos = i;
		}
	}
	return (player_pos);
}

void	change_player_texture(t_data *data, char *new)
{
	int	h;
	int	w;

	h = data->textures.height;
	w = data->textures.width;
	mlx_destroy_image(data->mlx_ptr, data->textures.player_texture);
	data->textures.player_texture = mlx_xpm_file_to_image(data->mlx_ptr, new,
			&h, &w);
}

void	change_exit_texture(t_data *data, char *new)
{
	int	h;
	int	w;

	h = data->textures.height;
	w = data->textures.width;
	++(data->current_cats);
	if (data->current_cats == data->total_cats)
	{
		mlx_destroy_image(data->mlx_ptr, data->textures.exit_texture);
		data->textures.exit_texture = mlx_xpm_file_to_image(data->mlx_ptr, new,
				&h, &w);
	}
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
