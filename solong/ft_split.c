/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabdessm <mabdessm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 12:44:33 by mabdessm          #+#    #+#             */
/*   Updated: 2024/08/17 05:25:51 by mabdessm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	count_words(char const *s, char c)
{
	int	i;
	int	nb;

	i = 0;
	nb = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c)
			i++;
		while (s[i] != '\0' && s[i] != c)
		{
			if (i == 0 || s[i - 1] == c)
				nb++;
			i++;
		}
	}
	return (nb);
}

int	len_word(char const *s, char c, int index)
{
	int	i;
	int	nb;
	int	lenword;

	i = 0;
	nb = 0;
	lenword = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c)
			i++;
		while (s[i] != '\0' && s[i] != c)
		{
			if (i == 0 || s[i - 1] == c)
				nb++;
			if (nb == index)
				lenword++;
			i++;
		}
	}
	return (lenword);
}

char	*get_word(char const *s, char c, int index)
{
	char	*word;
	int		i;
	int		j;
	int		nb;

	i = 0;
	j = 0;
	nb = 0;
	word = ft_calloc(sizeof(char), len_word(s, c, index) + 1);
	if (!word)
		return (NULL);
	while (s[i] != '\0')
	{
		while (s[i] == c)
			i++;
		while (s[i] != '\0' && s[i] != c)
		{
			if (i == 0 || s[i - 1] == c)
				nb++;
			if (nb == index)
				word[j++] = s[i];
			i++;
		}
	}
	return (word);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	char	**split;

	i = -1;
	split = ft_calloc(sizeof(char *), (count_words(s, c) + 1));
	if (!split || !s)
		return (NULL);
	while (++i < count_words(s, c))
		split[i] = get_word(s, c, i + 1);
	return (split);
}
