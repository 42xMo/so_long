/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabdessm <mabdessm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 16:42:23 by mabdessm          #+#    #+#             */
/*   Updated: 2024/08/28 20:28:09 by mabdessm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

//for testing
void	draw_map(char **map)
{
	int	i;

	i = -1;
	while (map && map[++i])
		ft_printf("%s\n", map[i]);
}

int	on_destroy(t_data *data)
{
	if (data->map)
	{
		ft_free_tab(data->map);
		mlx_destroy_image(data->mlx_ptr, data->textures.floor_texture);
		mlx_destroy_image(data->mlx_ptr, data->textures.wall_texture);
		mlx_destroy_image(data->mlx_ptr, data->textures.player_texture);
		mlx_destroy_image(data->mlx_ptr, data->textures.collectible1_texture);
		mlx_destroy_image(data->mlx_ptr, data->textures.collectible2_texture);
		mlx_destroy_image(data->mlx_ptr, data->textures.collectible3_texture);
		mlx_destroy_image(data->mlx_ptr, data->textures.collectible4_texture);
		mlx_destroy_image(data->mlx_ptr, data->textures.collectible5_texture);
		mlx_destroy_image(data->mlx_ptr, data->textures.collectible6_texture);
		mlx_destroy_image(data->mlx_ptr, data->textures.collectible7_texture);
		mlx_destroy_image(data->mlx_ptr, data->textures.collectible8_texture);
		mlx_destroy_image(data->mlx_ptr, data->textures.exit_texture);
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
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
	//only this part is missing, whenever one of these fours i pressed need
	//to move and change whatever happens in the game
	if (keysym == 97 || keysym == 100 || keysym == 119 || keysym == 115)
	{
		//only do printf if the character actually moved so it shoudln't count
		//if the character is in collision with a wall even if key is pressed
		printf("Number of Steps : %d\n", ++(data->steps));
	}
	return (0);
}

void	put_image(t_data *data, void *texture, int i, int j)
{
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
					texture, data->textures.width * j,
					data->textures.height * i);
}

int	draw_collectibles(t_data *data, int nb, int i, int j)
{
	if (nb == 0)
		put_image(data, data->textures.collectible1_texture, i, j);
	else if (nb == 1)
		put_image(data, data->textures.collectible2_texture, i, j);
	else if (nb == 2)
		put_image(data, data->textures.collectible3_texture, i, j);
	else if (nb == 3)
		put_image(data, data->textures.collectible4_texture, i, j);
	else if (nb == 4)
		put_image(data, data->textures.collectible5_texture, i, j);
	else if (nb == 5)
		put_image(data, data->textures.collectible6_texture, i, j);
	else if (nb == 6)
		put_image(data, data->textures.collectible7_texture, i, j);
	else if (nb == 7)
	{
		put_image(data, data->textures.collectible8_texture, i, j);
		nb = -1;
	}
	return (++nb);
}

int	draw_textures(t_data *data)
{
	int	i;
	int	j;
	int nb;

	nb = 0;
	i = -1;
	while (data->map[++i])
	{
		j = -1;
		while (data->map[i][++j])
		{
			if (data->map[i][j] == '1')
				put_image(data, data->textures.wall_texture, i, j);
			if (data->map[i][j] == '0')
				put_image(data, data->textures.floor_texture, i, j);
			if (data->map[i][j] == 'P')
				put_image(data, data->textures.player_texture, i, j);
			if (data->map[i][j] == 'C')
				nb = draw_collectibles(data, nb, i, j);
			if (data->map[i][j] == 'E')
				put_image(data, data->textures.exit_texture, i, j);
		}
	}
	return (0);
}

void	render_textures(t_data *data)
{
	data->win_ptr = mlx_new_window(data->mlx_ptr,
					(data->width * data->textures.width),
					(data->height * data->textures.height), "so_long");
	if (!data->win_ptr)
	{
		free(data->mlx_ptr);
		return ;
	}
	mlx_loop_hook(data->mlx_ptr, &draw_textures, data);
	mlx_hook(data->win_ptr, KeyRelease, KeyReleaseMask, &on_keypress, data);
	mlx_hook(data->win_ptr, DestroyNotify, StructureNotifyMask,
			&on_destroy, data);
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
	load_collectibles(data, h , w);
	data->textures.floor_texture = mlx_xpm_file_to_image(data->mlx_ptr,
									 "./textures/floor.xpm", &h, &w);
	data->textures.wall_texture = mlx_xpm_file_to_image(data->mlx_ptr,
									 "./textures/wall.xpm", &h, &w);
	data->textures.player_texture = mlx_xpm_file_to_image(data->mlx_ptr,
									 "./textures/player.xpm", &h, &w);
	data->textures.exit_texture = mlx_xpm_file_to_image(data->mlx_ptr,
									 "./textures/exit_closed.xpm", &h, &w);
}

void	assign_size(t_data *data)
{
	int	i;
	int	j;

	i = -1;
	while (data->map[++i])
	{
		j = 0;
		while (data->map[i][j])
			++j;
	}
	data->height = i;
	data->width = j;
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
		draw_map(data.map);
		load_textures(&data);
		render_textures(&data);
	}
	else
		return (!return_error("Invalid number of arguments!"));
}
