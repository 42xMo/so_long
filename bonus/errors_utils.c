/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabdessm <mabdessm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 07:55:51 by mabdessm          #+#    #+#             */
/*   Updated: 2024/08/31 05:35:44 by mabdessm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

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

int	invalid_character(char c)
{
	if (c != '0' && c != '1' && c != 'C' && c != 'E' && c != 'P' && c != '\n'
		&& c != 'F')
		return (1);
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
	{
		free(buffer);
		return_error("Map contains an empty line!");
	}
	return (NULL);
}
