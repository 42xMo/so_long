/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabdessm <mabdessm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 14:58:24 by mabdessm          #+#    #+#             */
/*   Updated: 2024/08/30 13:48:00 by mabdessm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../minilibx-linux/mlx.h"
# include "../minilibx-linux/mlx_int.h"
# include "../getnextline/get_next_line.h"
# include "../printf/ft_printf.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

void			ft_bzero(void *s, size_t n);
void			*ft_calloc(size_t nmemb, size_t size);
int				count_words(char const *s, char c);
int				len_word(char const *s, char c, int index);
char			*get_word(char const *s, char c, int index);
char			**ft_split(char const *s, char c);

typedef struct s_point
{
	int			x;
	int			y;
}				t_point;

typedef struct s_textures
{
	int		height;
	int		width;
	void	*wall_texture;
	void	*player_texture;
	void	*exit_texture;
	void	*collectible1_texture;
	void	*collectible2_texture;
	void	*collectible3_texture;
	void	*collectible4_texture;
	void	*collectible5_texture;
	void	*collectible6_texture;
	void	*collectible7_texture;
	void	*collectible8_texture;
	void	*floor_texture;
}			t_textures;

typedef struct s_data
{
	void		*mlx_ptr;
	void		*win_ptr;
	char		**map;
	int			height;
	int			width;
	int			steps;
	int			exit;
	int			total_cats;
	int			current_cats;
	int			cat_color;
	t_textures	textures;
}				t_data;

void			fill(char **tab, t_point size, t_point cur, char to_fill);
void			flood_fill(char **tab, t_point size, t_point begin);
char			**make_area(char **zone, t_point size);
void			ft_free_tab(char **str);
int				return_error(char *str);
int				invalid_file(char *str);
unsigned int	ft_strstrlen(char **str);
int				e_p_c_error(int exit, int start, int collectible);
int				invalid_e_p_c(char **map);
int				invalid_character(char c);
int				no_map_errors(char **map);
int				no_path_to_p(char **tab, t_point size, unsigned int x,
					unsigned int y);
int				free_and_return(char **tab, char c);
void			double_free(char *str1, char *str2);
int				check_paths(char **map, char **temp, t_point size);
int				valid_paths(char **map);
int				empty_lines_in_map(char *buffer);
char			**file_errors(int fd, char *file);
char			**buffer_errors(char *buffer);
char			**check_errors(char *file);
char			**check_file_errors(int fd);

#endif