/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabdessm <mabdessm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 07:57:18 by mabdessm          #+#    #+#             */
/*   Updated: 2024/08/17 07:58:54 by mabdessm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	e_p_c_error(int exit, int start, int collectible)
{
	if (start != 1)
	{
		ft_printf("\033[0;31mError\n");
		ft_printf("Map has %i start positions! It needs to have 1!\n\033[0m",
			start);
		return (1);
	}
	else if (collectible < 1)
	{
		return_error("Map has no collectibles! It needs to have at least 1!");
		return (1);
	}
	else if (exit != 1)
	{
		ft_printf("\033[0;31mError\n");
		ft_printf("Map has %i exits! It needs to have 1!\n\033[0m", exit);
		return (1);
	}
	return (0);
}

int	invalid_e_p_c(char **map)
{
	int	exit;
	int	start;
	int	collectible;
	int	i;
	int	j;

	i = -1;
	exit = 0;
	start = 0;
	collectible = 0;
	while (map && map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (map[i][j] == 'E')
				++exit;
			if (map[i][j] == 'P')
				++start;
			if (map[i][j] == 'C')
				++collectible;
		}
	}
	return (e_p_c_error(exit, start, collectible));
}

int	no_path_to_p(char **tab, t_point size, unsigned int x, unsigned int y)
{
	int		i;
	int		j;
	t_point	begin;

	begin.x = x;
	begin.y = y;
	flood_fill(tab, size, begin);
	i = -1;
	while (++i < size.y)
	{
		j = -1;
		while (++j < size.x)
		{
			if (tab[i][j] == 'P')
				return (1);
		}
	}
	return (0);
}

int	check_paths(char **map, char **temp, t_point size)
{
	unsigned int	i;
	unsigned int	j;

	i = -1;
	while (map && map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (map[i][j] == 'E')
			{
				if (no_path_to_p(temp, size, j, i))
					return (free_and_return(temp, 'e'));
			}
			if (map[i][j] == 'C')
			{
				if (no_path_to_p(temp, size, j, i))
					return (free_and_return(temp, 'c'));
				ft_free_tab(temp);
				temp = make_area(map, size);
			}
		}
	}
	ft_free_tab(temp);
	return (1);
}

int	valid_paths(char **map)
{
	char			**temp;
	t_point			size;

	size.x = ft_strlen(map[0]);
	size.y = ft_strstrlen(map);
	temp = make_area(map, size);
	if (!temp)
		return (0);
	if (!check_paths(map, temp, size))
		return (0);
	return (1);
}
