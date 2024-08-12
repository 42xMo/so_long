/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabdessm <mabdessm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 16:42:23 by mabdessm          #+#    #+#             */
/*   Updated: 2024/08/12 05:21:08 by mabdessm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

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

int	E_P_C_error(int exit, int start, int collectible)
{
	if (start != 1)
	{
		ft_printf("\033[0;31mError\n");
		ft_printf("Map has %i start positions! It needs to have 1!", start);
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
		ft_printf("Map has %i exits! It needs to have 1!", exit);
		return (1);
	}
	return (0);
}

int	invalid_E_P_C(char **map)
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
	return (E_P_C_error(exit, start, collectible));
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
			return(return_error("Map is missing outter walls!"));
	}
	return (!(invalid_E_P_C(map)));
}

int	valid_paths(char **map)
{
	int	i;
	int	j;

	i = -1;
	while (map && map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
		}
	}
	return (1);
}

int		empty_lines_in_map(char *buffer)
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

	fd = open(file, O_RDONLY);
	if (fd < 0 || invalid_file(file))
		return (file_errors(fd, file));
	buffer = get_next_line(fd);
	temp = get_next_line(fd);
	while (temp)
	{
		buffer = ft_strjoin(buffer, temp);
		temp = get_next_line(fd);
	}
	if (!buffer || empty_lines_in_map(buffer))
		return (buffer_errors(buffer));
	map = ft_split(buffer, '\n');
	if (no_map_errors(map) && valid_paths(map))
		return (map);
	return (NULL);
}

void	draw_map(char **map)
{
	int	i;

	i = -1;
	while (map && map[++i])
		ft_printf("%s\n", map[i]);
}

int	main(int argc, char **argv)
{
	char **map;
	
	if (argc == 2)
	{
		map = check_errors(argv[1]);
		draw_map(map);
	}
	else
		return_error("Invalid number of arguments!");
}

/*MAP PARSING*/
//error if open fails														DONE
//error if the file doesnt end in .ber	 									DONE
//error if file is empty													DONE
//the map must be surrounded by walls otherwise return an error				DONE
//the map can only be composed of 0 for empty space, 1 for a wall, C for	DONE
//a collectible, E for a map exit and P for the player start position		DONE
//the map must be rectangular												DONE
//error if empty line in beetween or at the start of the map				DONE
//for me i decided to accept if the map has a \n at the end of every line	DONE
//even the last one, i dont accept \n at the start or two consecutive \n	DONE
//a valid map has 1 exit, 1 starting position and at least 1 collectible	DONE
//if the map has duplicate (more than 1) exit or start,display an error		DONE

//error if no path to exit or/and to collectibles						
//error msg if no path to collectibles = "no valid path to one or multiple 
//collectibles" (cool if i can say how many but not necessary)
//error msg if no path to exit = "no valid path to exit"


//You must be able to parse any kind of map, as long as it respects the above rules.

//If any misconfiguration of any kind is encountered in the file, the program
//must exit in a clean way, and return "Error\n" followed by an explicit error 
//message of your choice.
//examples of errors/msgs : an unknown character, duplicates, an invalid file path...

//if a malloc fails the error is 'memory allocation error'

//favourite function : invalid_E_P_C because it's goofy