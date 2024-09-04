/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabdessm <mabdessm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 08:01:58 by mabdessm          #+#    #+#             */
/*   Updated: 2024/09/04 21:01:59 by mabdessm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

unsigned int	ft_strstrlen(char **str)
{
	int	i;

	i = 0;
	while (str && str[i])
		++i;
	return (i);
}

void	put_back_exit(t_data *data, int i, int j)
{
	(data->map)[j][i] = 'E';
	data->exit = 0;
}

void	check_end(t_data *data, char *str)
{
	change_player_texture(data, str);
	data->exit = 1;
	if (data->current_cats == data->total_cats)
	{
		++data->steps;
		end_screen(data, "./textures/gab_floating_head.xpm",
			"./textures/gab_x_men.xpm");
	}
}

void	put_number_steps(t_data *data)
{
	char	*steps;
	char	*str;

	steps = ft_itoa(data->steps);
	str = ft_strjoin("Number of Steps : ", steps);
	mlx_string_put(data->mlx_ptr, data->win_ptr, data->textures.width * 1.25,
		data->textures.height / 2, 0xFFFF00, str);
	free (steps);
	free (str);
}

void	destroy_images(t_data *data)
{
	mlx_destroy_image(data->mlx_ptr, data->textures.floor_texture);
	mlx_destroy_image(data->mlx_ptr, data->textures.wall_texture);
	mlx_destroy_image(data->mlx_ptr, data->textures.player_texture);
	mlx_destroy_image(data->mlx_ptr, data->textures.exit_texture);
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	mlx_destroy_image(data->mlx_ptr, data->textures.collectible1_texture);
	mlx_destroy_image(data->mlx_ptr, data->textures.collectible2_texture);
	mlx_destroy_image(data->mlx_ptr, data->textures.collectible3_texture);
	mlx_destroy_image(data->mlx_ptr, data->textures.collectible4_texture);
	mlx_destroy_image(data->mlx_ptr, data->textures.collectible5_texture);
	mlx_destroy_image(data->mlx_ptr, data->textures.collectible6_texture);
	mlx_destroy_image(data->mlx_ptr, data->textures.collectible7_texture);
	mlx_destroy_image(data->mlx_ptr, data->textures.collectible8_texture);
	mlx_destroy_image(data->mlx_ptr, data->textures.enemy1_texture);
	mlx_destroy_image(data->mlx_ptr, data->textures.enemy2_texture);
	mlx_destroy_image(data->mlx_ptr, data->textures.enemy3_texture);
	mlx_destroy_image(data->mlx_ptr, data->textures.enemy4_texture);
	mlx_destroy_image(data->mlx_ptr, data->textures.enemy5_texture);
	mlx_destroy_image(data->mlx_ptr, data->textures.enemy6_texture);
}
