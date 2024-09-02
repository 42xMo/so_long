/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabdessm <mabdessm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 19:55:25 by mabdessm          #+#    #+#             */
/*   Updated: 2024/09/02 19:58:21 by mabdessm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

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
