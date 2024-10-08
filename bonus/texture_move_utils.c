/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_move_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabdessm <mabdessm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 15:28:47 by mabdessm          #+#    #+#             */
/*   Updated: 2024/09/04 21:17:18 by mabdessm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

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

void	end_screen(t_data *data, char *str, char *str2)
{
	int	i;
	int	j;

	i = -1;
	while (data->map[++i])
	{
		j = -1;
		while (data->map[i][++j])
		{
			data->map[i][j] = 'P';
		}
	}
	i = -1;
	while (++i < 6)
	{
		change_player_texture(data, str);
		draw_textures(data);
		usleep(100000);
		change_player_texture(data, str2);
		draw_textures(data);
		usleep(200000);
	}
	on_destroy(data);
}
