/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabdessm <mabdessm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 16:42:23 by mabdessm          #+#    #+#             */
/*   Updated: 2024/08/17 06:37:14 by mabdessm         ###   ########.fr       */
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

void	ft_free_tab(char **str)
{
	int	i;

	i = -1;
	while (str[++i])
		free (str[i]);
	free (str);
}

int	return_error(char *str)
{
	ft_printf("\033[0;31mError\n");
	ft_printf("%s\n\033[0m", str);
	return (0);
}

int	invalid_file(char *str)
{
	int	i;

	i = ft_strlen(str) - 1;
	if (!str[i] || str[i] != 'r')
		return (1);
	--i;
	if (!str[i] || str[i] != 'e')
		return (1);
	--i;
	if (!str[i] || str[i] != 'b')
		return (1);
	--i;
	if (!str[i] || str[i] != '.')
		return (1);
	--i;
	if (!str[i])
		return (1);
	return (0);
}

unsigned int	ft_strstrlen(char **str)
{
	int	i;

	i = 0;
	while (str && str[i])
		++i;
	return (i);
}

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

int	invalid_character(char c)
{
	if (c != '0' && c != '1' && c != 'C' && c != 'E' && c != 'P' && c != '\n')
		return (1);
	return (0);
}

int	no_map_errors(char **map)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	line_len;

	i = -1;
	line_len = ft_strlen(map[0]);
	while (map && map[++i])
	{
		if (ft_strlen(map[i]) != line_len)
			return (return_error("Map is not rectangular!"));
		j = -1;
		while (map[i][++j])
		{
			if (invalid_character(map[i][j]))
				return (return_error("Invalid characters in map!"));
			if (i == 0 || i == (ft_strstrlen(map) - 1))
			{
				if (map[i][j] != '1')
					return (return_error("Map is missing outter walls!"));
			}
		}
		if (map[i][0] != '1' || map[i][ft_strlen(map[i]) - 1] != '1')
			return (return_error("Map is missing outter walls!"));
	}
	return (!(invalid_e_p_c(map)));
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

int	free_and_return(char **tab, char c)
{
	if (c == 'e')
	{
		ft_free_tab(tab);
		return (return_error("No valid exit path!"));
	}
	else
	{
		ft_free_tab(tab);
		return (return_error("No valid collectibles path!"));
	}
}

int	check_paths(char **map, char **temp, t_point size)
{
	unsigned int	i;
	unsigned int 	j;

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
	{
		ft_free_tab(temp);
		return (0);
	}
	ft_free_tab(temp);
	return (1);
}

int	empty_lines_in_map(char *buffer)
{
	int	i;

	i = 0;
	if (buffer[i] == '\n')
		return (1);
	while (buffer[i] && buffer[i + 1])
	{
		if (buffer[i] == '\n' && buffer[i + 1] == '\n')
			return (1);
		++i;
	}
	return (0);
}

char	**file_errors(int fd, char *file)
{
	if (fd < 0)
		return_error("Argument doesn't exist or is not a file!");
	else if (invalid_file(file))
		return_error("Invalid file type!");
	return (NULL);
}

char	**buffer_errors(char *buffer)
{
	if (!buffer)
		return_error("File is empty!");
	else if (empty_lines_in_map(buffer))
		return_error("Map contains an empty line!");
	return (NULL);
}

char	**check_errors(char *file)
{
	int		fd;
	char	**map;
	char	*temp;
	char	*buffer;
	char	*old_buffer;

	fd = open(file, O_RDONLY);
	if (fd < 0 || invalid_file(file))
		return (file_errors(fd, file));
	buffer = get_next_line(fd);
    // if (!buffer)
    //     return (buffer_errors(NULL));
	temp = get_next_line(fd);
	while (temp)
	{
		old_buffer = buffer;
		buffer = ft_strjoin(buffer, temp);
		free(old_buffer);
		free (temp);
		temp = get_next_line(fd);
	}
	close(fd);
	if (!buffer || empty_lines_in_map(buffer))
	{
		//free(buffer);
		return (buffer_errors(buffer));
	}
	map = ft_split(buffer, '\n');
	free(buffer);
	// free(temp);
	if (no_map_errors(map) && valid_paths(map))
		return (map);
	return (NULL);
}

int	main(int argc, char **argv)
{
	char	**map;

	if (argc == 2)
	{
		map = check_errors(argv[1]);
		if (!map)
			return (0);
		draw_map(map);
		ft_free_tab(map);
		//241 byte(s) leaked in 1 allocation(s) for empty line at start and beetween
		//241 byte(s) leaked in 1 allocation(s) for 2 empty line at end
		//108 byte(s) leaked in 6 allocation(s) for no collectible path
		//216 byte(s) leaked in 12 allocation(s) for no exit path
		//leaks for big maps but not small maps
	}
	else
		return (return_error("Invalid number of arguments!"));
}
