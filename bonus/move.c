/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabdessm <mabdessm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 15:34:21 by mabdessm          #+#    #+#             */
/*   Updated: 2024/09/04 21:13:11 by mabdessm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

void	move_left(t_data *data)
{
	int	i;
	int	j;

	i = get_player_i_pos(data);
	j = get_player_j_pos(data);
	change_player_texture(data, "./textures/player_left.xpm");
	if (i != 0 && (data->map)[j][i - 1] == '1')
	{
		if (data->exit)
			change_player_texture(data,
				"./textures/player_left_exit_closed.xpm");
		return ;
	}
	if (data->exit)
		put_back_exit(data, i, j);
	else
		(data->map)[j][i] = '0';
	if (i != 0 && (data->map)[j][i - 1] == 'C')
		change_exit_texture(data, "./textures/exit_open.xpm");
	if (i != 0 && (data->map)[j][i - 1] == 'E')
		check_end(data, "./textures/player_left_exit_closed.xpm");
	if (i != 0 && (data->map)[j][i - 1] == 'F')
		end_screen(data, "./textures/gab_sad.xpm", "./textures/gab_sad_2.xpm");
	(data->map)[j][i - 1] = 'P';
	++(data->steps);
}

void	move_right(t_data *data)
{
	int	i;
	int	j;

	i = get_player_i_pos(data);
	j = get_player_j_pos(data);
	change_player_texture(data, "./textures/player_right.xpm");
	if (i != data->width && (data->map)[j][i + 1] == '1')
	{
		if (data->exit)
			change_player_texture(data,
				"./textures/player_right_exit_closed.xpm");
		return ;
	}
	if (data->exit)
		put_back_exit(data, i, j);
	else
		(data->map)[j][i] = '0';
	if (i != data->width && (data->map)[j][i + 1] == 'C')
		change_exit_texture(data, "./textures/exit_open.xpm");
	if (i != data->width && (data->map)[j][i + 1] == 'E')
		check_end(data, "./textures/player_right_exit_closed.xpm");
	if (i != data->width && (data->map)[j][i + 1] == 'F')
		end_screen(data, "./textures/gab_sad.xpm", "./textures/gab_sad_2.xpm");
	(data->map)[j][i + 1] = 'P';
	++(data->steps);
}

void	move_up(t_data *data)
{
	int	i;
	int	j;

	i = get_player_i_pos(data);
	j = get_player_j_pos(data);
	change_player_texture(data, "./textures/player_up.xpm");
	if (j != 0 && (data->map)[j - 1][i] == '1')
	{
		if (data->exit)
			change_player_texture(data, "./textures/player_up_exit_closed.xpm");
		return ;
	}
	if (data->exit)
		put_back_exit(data, i, j);
	else
		(data->map)[j][i] = '0';
	if (j != 0 && (data->map)[j - 1][i] == 'C')
		change_exit_texture(data, "./textures/exit_open.xpm");
	if (j != 0 && (data->map)[j - 1][i] == 'E')
		check_end(data, "./textures/player_up_exit_closed.xpm");
	if (j != 0 && (data->map)[j - 1][i] == 'F')
		end_screen(data, "./textures/gab_sad.xpm", "./textures/gab_sad_2.xpm");
	(data->map)[j - 1][i] = 'P';
	++(data->steps);
}

void	move_down(t_data *data)
{
	int	i;
	int	j;

	i = get_player_i_pos(data);
	j = get_player_j_pos(data);
	change_player_texture(data, "./textures/gab.xpm");
	if (j != data->height && (data->map)[j + 1][i] == '1')
	{
		if (data->exit)
			change_player_texture(data, "./textures/gab_exit_closed.xpm");
		return ;
	}
	if (data->exit)
		put_back_exit(data, i, j);
	else
		(data->map)[j][i] = '0';
	if (j != data->height && (data->map)[j + 1][i] == 'C')
		change_exit_texture(data, "./textures/exit_open.xpm");
	if (j != data->height && (data->map)[j + 1][i] == 'E')
		check_end(data, "./textures/gab_exit_closed.xpm");
	if (j != data->height && (data->map)[j + 1][i] == 'F')
		end_screen(data, "./textures/gab_sad.xpm", "./textures/gab_sad_2.xpm");
	(data->map)[j + 1][i] = 'P';
	++(data->steps);
}

void	put_image(t_data *data, void *texture, int i, int j)
{
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, texture,
		data->textures.width * j, data->textures.height * i);
	put_number_steps(data);
}
