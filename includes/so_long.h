/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabdessm <mabdessm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 14:58:24 by mabdessm          #+#    #+#             */
/*   Updated: 2024/08/17 01:45:41 by mabdessm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../.minilibx-linux/mlx.h"
# include "../printf/ft_printf.h"
# include "../getnextline/get_next_line.h"

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>

void	draw_map(char **map);

void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t nmemb, size_t size);

int		count_words(char const *s, char c);
int		len_word(char const *s, char c, int index);
char	*get_word(char const *s, char c, int index);
char	**ft_split(char const *s, char c);

typedef struct s_point
{
	int		x;
	int		y;
}	t_point;

void	fill(char **tab, t_point size, t_point cur, char to_fill);
void	flood_fill(char **tab, t_point size, t_point begin);
char	**make_area(char **zone, t_point size);

#endif