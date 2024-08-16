/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flood_fill.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabdessm <mabdessm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 23:34:14 by mabdessm          #+#    #+#             */
/*   Updated: 2024/08/17 01:47:28 by mabdessm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	fill(char **tab, t_point size, t_point cur, char to_not_fill)
{
	if (cur.y < 0 || cur.y >= size.y || cur.x < 0 || cur.x >= size.x
		|| tab[cur.y][cur.x] == to_not_fill || tab[cur.y][cur.x] == 'F')
		return ;
	tab[cur.y][cur.x] = 'F';
	fill(tab, size, (t_point){cur.x - 1, cur.y}, to_not_fill);
	fill(tab, size, (t_point){cur.x + 1, cur.y}, to_not_fill);
	fill(tab, size, (t_point){cur.x, cur.y - 1}, to_not_fill);
	fill(tab, size, (t_point){cur.x, cur.y + 1}, to_not_fill);
}

void	flood_fill(char **tab, t_point size, t_point begin)
{
	fill(tab, size, begin, '1');
}

char	**make_area(char **zone, t_point size)
{
	char	**new;
	int		i;
	int		j;

	new = malloc(sizeof(char *) * size.y);
	i = 0;
	while (i < size.y)
	{
		new[i] = malloc(size.x + 1);
		j = 0;
		while (j < size.x)
		{
			new[i][j] = zone[i][j];
			++j;
		}
		new[i][size.x] = '\0';
		++i;
	}
	return (new);
}

/*int main(void)
{
	t_point size;
	t_point	begin;
	char	**area;

	size.x = 13;
	size.y = 5;
	
	char *zone[] = {
		"1111111111111",
		"10010000000C1",
		"1000011111001",
		"1P0011E000001",
		"1111111111111",
	};
	
	area = make_area(zone, size);
	
	for (int i = 0; i < size.y; ++i)
		printf("%s\n", area[i]);
	printf("\n");

	begin.x = 11;
	begin.y = 1;
	flood_fill(area, size, begin);


	for (int i = 0; i < size.y; ++i)
		printf("%s\n", area[i]);

	return (0);
}*/
