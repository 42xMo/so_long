/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabdessm <mabdessm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 16:42:23 by mabdessm          #+#    #+#             */
/*   Updated: 2024/08/07 21:38:26 by mabdessm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	return_error(char *str)
{
	ft_printf("Error\n");
	ft_printf("%s\n", str);
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

void	check_map_errors(char *buffer)
{
	if (!buffer)
		return_error("File is empty!");
}

void	check_errors(char *file)
{
	int		fd;
	char	*buffer;
	int		i;

	fd = open(file, O_RDONLY);
	buffer = NULL;
	i = 0;
	if (fd < 0)
		return_error("Argument doesn't exist or is not a file!");
	else if (invalid_file(file))
		return_error("Invalid file type!");
	else
	{
		buffer = get_next_line(fd);
		check_map_errors(buffer);
	}
	free(buffer);
	close(fd);
}

//maybe if it's more convenient, it's better to have the fd in main
//then take it as argument to check for errors
//otherwise i can just close then reopen in main but why just not open
//directly there whatever is more clear i guess

int	main(int argc, char **argv)
{
	if (argc == 2)
		check_errors(argv[1]);
	else
		return_error("Invalid number of arguments!");
}

/*MAP PARSING*/
//error if open(argv[1]) is < 0 			DONE
//error if the file doesnt end in .ber	 	DONE
//error if file is empty					DONE

//error if empty line in beetween, at the start or at the end inside the map
//error if no path to exit or/and to collectibles
//the map can only be composed of 0 for empty space, 1 for a wall, C for a collectible
//E for a map exit and P for the player start position
//the map has to be constructed with 3 components, walls, collectibles and free space
//a valid map has 1 exit, 1 starting position and at least 1 collectible
//if the map has duplicate (more than 1) exit or start,display an error msg
//the map must be rectangular
//the map must be surrounded by walls otherwise return an error
//need to check if there is a valid path in the map
//You must be able to parse any kind of map, as long as it respects the above rules.
//If any misconfiguration of any kind is encountered in the file, the program
//must exit in a clean way, and return "Error\n" followed by an explicit error 
//message of your choice.
//examples of errors/msgs : an unknown character, duplicates, an invalid file path...