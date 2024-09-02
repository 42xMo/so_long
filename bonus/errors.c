/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabdessm <mabdessm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 07:52:15 by mabdessm          #+#    #+#             */
/*   Updated: 2024/08/31 05:35:53 by mabdessm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

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

char	**check_errors(char *file)
{
	int	fd;

	fd = open(file, O_RDONLY);
	if (fd < 0 || invalid_file(file))
		return (file_errors(fd, file));
	return (check_file_errors(fd));
}

char	**check_file_errors(int fd)
{
	char	**map;
	char	*temp;
	char	*buffer;
	char	*old_buffer;

	buffer = get_next_line(fd);
	if (!buffer)
		return (buffer_errors(NULL));
	temp = get_next_line(fd);
	while (temp)
	{
		old_buffer = buffer;
		buffer = ft_strjoin(buffer, temp);
		double_free(old_buffer, temp);
		temp = get_next_line(fd);
	}
	close(fd);
	if (!buffer || empty_lines_in_map(buffer))
		return (buffer_errors(buffer));
	map = ft_split(buffer, '\n');
	free(buffer);
	if (no_map_errors(map) && valid_paths(map))
		return (map);
	ft_free_tab(map);
	return (NULL);
}
