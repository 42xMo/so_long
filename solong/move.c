/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabdessm <mabdessm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 15:34:21 by mabdessm          #+#    #+#             */
/*   Updated: 2024/08/30 15:36:59 by mabdessm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	move_left(t_data *data)
{
	int	i;
	int	j;

	i = get_player_i_pos(data);
	j = get_player_j_pos(data);
	if (i != 0 && (data->map)[j][i - 1] == '1')
		return ;
	change_player_texture(data, "./textures/player_left.xpm");
	if (data->exit)
		put_back_exit(data, i, j);
	else
		(data->map)[j][i] = '0';
	if (i != 0 && (data->map)[j][i - 1] == 'C')
		change_exit_texture(data, "./textures/exit_open.xpm");
	if (i != 0 && (data->map)[j][i - 1] == 'E')
	{
		change_player_texture(data, "./textures/player_left_exit_closed.xpm");
		data->exit = 1;
		if (data->current_cats == data->total_cats)
			on_destroy(data);
	}
	(data->map)[j][i - 1] = 'P';
	printf("Number of Steps : %d\n", ++(data->steps));
}

void	move_right(t_data *data)
{
	int	i;
	int	j;

	i = get_player_i_pos(data);
	j = get_player_j_pos(data);
	if (i != data->width && (data->map)[j][i + 1] == '1')
		return ;
	change_player_texture(data, "./textures/player_right.xpm");
	if (data->exit)
		put_back_exit(data, i, j);
	else
		(data->map)[j][i] = '0';
	if (i != data->width && (data->map)[j][i + 1] == 'C')
		change_exit_texture(data, "./textures/exit_open.xpm");
	if (i != data->width && (data->map)[j][i + 1] == 'E')
	{
		change_player_texture(data, "./textures/player_right_exit_closed.xpm");
		data->exit = 1;
		if (data->current_cats == data->total_cats)
			on_destroy(data);
	}
	(data->map)[j][i + 1] = 'P';
	printf("Number of Steps : %d\n", ++(data->steps));
}

void	move_up(t_data *data)
{
	int	i;
	int	j;

	i = get_player_i_pos(data);
	j = get_player_j_pos(data);
	if (j != 0 && (data->map)[j - 1][i] == '1')
		return ;
	change_player_texture(data, "./textures/player_up.xpm");
	if (data->exit)
		put_back_exit(data, i, j);
	else
		(data->map)[j][i] = '0';
	if (j != 0 && (data->map)[j - 1][i] == 'C')
		change_exit_texture(data, "./textures/exit_open.xpm");
	if (j != 0 && (data->map)[j - 1][i] == 'E')
	{
		change_player_texture(data, "./textures/player_up_exit_closed.xpm");
		data->exit = 1;
		if (data->current_cats == data->total_cats)
			on_destroy(data);
	}
	(data->map)[j - 1][i] = 'P';
	printf("Number of Steps : %d\n", ++(data->steps));
}

void	move_down(t_data *data)
{
	int	i;
	int	j;

	i = get_player_i_pos(data);
	j = get_player_j_pos(data);
	if (j != data->height && (data->map)[j + 1][i] == '1')
		return ;
	change_player_texture(data, "./textures/player.xpm");
	if (data->exit)
		put_back_exit(data, i, j);
	else
		(data->map)[j][i] = '0';
	if (j != data->height && (data->map)[j + 1][i] == 'C')
		change_exit_texture(data, "./textures/exit_open.xpm");
	if (j != data->height && (data->map)[j + 1][i] == 'E')
	{
		change_player_texture(data, "./textures/player_exit_closed.xpm");
		data->exit = 1;
		if (data->current_cats == data->total_cats)
			on_destroy(data);
	}
	(data->map)[j + 1][i] = 'P';
	printf("Number of Steps : %d\n", ++(data->steps));
}

void	put_image(t_data *data, void *texture, int i, int j)
{
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, texture,
		data->textures.width * j, data->textures.height * i);
}
