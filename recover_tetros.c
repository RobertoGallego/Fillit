/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recover_tetros.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmorgan- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/11 11:58:37 by pmorgan-          #+#    #+#             */
/*   Updated: 2019/01/14 17:57:03 by pmorgan-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

_Bool		check_empty_line_and_error(char *str, int j)
{
	if (ft_strcmp(str, "") == 0 && j != 0)
	{
		free(str);
		return (1);
	}
	return (0);
}

int			check_empty_line_and_continue(char *str, int j)
{
	if (ft_strcmp(str, "") == 0 && j == 0)
	{
		free(str);
		return (1);
	}
	return (0);
}

_Bool		copy_tetri(char *filename, int *num_tetri, t_tetro *tetro, int fd)
{
	char	*str;
	int		i;
	int		j;

	fd = open(filename, O_RDONLY);
	i = -1;
	while (++i < *num_tetri)
	{
		j = 0;
		while (j < 4)
		{
			if (get_next_line(fd, &str) == -1)
				return (0);
			if (check_empty_line_and_continue(str, j) == 1)
				continue;
			if (check_empty_line_and_error(str, j) == 1)
				return (error_msg());
			if (!(tetro[i].array[j] = ft_strdup(str)))
				return (0);
			free(str);
			j++;
		}
	}
	close(fd);
	return (1);
}

void		find_tetro_edges(t_tetro *tetro)
{
	tetro->tl.x = find_left_edge(*tetro);
	tetro->tl.y = find_top_bottom(*tetro, 1);
	tetro->br.x = find_right_edge(*tetro);
	tetro->br.y = find_top_bottom(*tetro, 0);
}

t_tetro		*recover_tetros(char *filename, int *num_tetri)
{
	int		i;
	t_tetro	*tetro;

	if (!count_tetros(filename, num_tetri))
		return ((t_tetro*)error_msg());
	if (!(tetro = (t_tetro*)malloc((*num_tetri + 1) * sizeof(t_tetro))))
		return (NULL);
	i = -1;
	while (++i < *num_tetri)
		if (!(tetro[i].array = (char**)malloc(4 * sizeof(char*))))
			return (NULL);
	if (!(copy_tetri(filename, num_tetri, tetro, 0)))
		return (NULL);
	if (!(check_tetro_chars(tetro, *num_tetri)))
		return ((t_tetro*)error_msg());
	i = -1;
	while (++i < *num_tetri)
	{
		if (!count_hashtags(&(tetro[i])))
			return ((t_tetro*)error_msg());
		find_tetro_edges(&(tetro[i]));
	}
	tetro[i].array = NULL;
	return (tetro);
}
