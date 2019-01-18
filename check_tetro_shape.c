/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_tetro_shape.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmorgan- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/14 11:55:43 by pmorgan-          #+#    #+#             */
/*   Updated: 2019/01/17 12:23:53 by pmorgan-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			check_shape_y_axis(t_tetro *tetro)
{
	int		i;
	int		j;
	int		edges;

	edges = 0;
	i = -1;
	while (++i < 4)
	{
		j = -1;
		while (++j < 4)
		{
			if (tetro->array[i][j] == tetro->id)
			{
				if (i != 0)
					if (tetro->array[i - 1][j] == tetro->id)
						++edges;
				if (i != 3)
					if (tetro->array[i + 1][j] == tetro->id)
						++edges;
			}
		}
	}
	return (edges);
}

int			check_shape_x_axis(t_tetro *tetro)
{
	int		i;
	int		j;
	int		edges;

	edges = 0;
	i = -1;
	while (++i < 4)
	{
		j = -1;
		while (++j < 4)
		{
			if (tetro->array[i][j] == tetro->id)
			{
				if (j != 0)
					if (tetro->array[i][j - 1] == tetro->id)
						++edges;
				if (j != 3)
					if (tetro->array[i][j + 1] == tetro->id)
						++edges;
			}
		}
	}
	return (edges);
}

_Bool		count_hashtags(t_tetro *tetro)
{
	int	hashtag_count;
	int	i;
	int j;

	hashtag_count = 0;
	i = -1;
	while (++i < 4)
	{
		if (ft_strlen(tetro->array[i]) != 4)
			return (0);
		j = -1;
		while (++j < 4)
		{
			if (tetro->array[i][j] == tetro->id)
				hashtag_count++;
			else if (tetro->array[i][j] != '.')
				return (0);
		}
	}
	if (hashtag_count != 4)
		return (0);
	if (check_shape_y_axis(tetro) + check_shape_x_axis(tetro) < 6)
		return (0);
	return (1);
}

_Bool		count_tetros(char *filename, int *num_tetri)
{
	char	*str;
	int		fd;
	int		line_count;

	line_count = 0;
	fd = open(filename, O_RDONLY);
	while (get_next_line(fd, &str) == 1)
	{
		line_count++;
		ft_strdel(&str);
	}
	close(fd);
	if ((line_count + 1) % 5 != 0)
		return (0);
	*num_tetri = (line_count + 1) / 5;
	if (*num_tetri > 26)
		return (0);
	return (1);
}

_Bool		check_tetro_chars(t_tetro *tetro, int num_tetri)
{
	int		i;
	int		j;
	int		k;
	char	id;

	id = 'A';
	i = -1;
	while (++i < num_tetri)
	{
		tetro[i].id = id++;
		j = -1;
		while (++j < 4)
		{
			k = -1;
			while (++k < 4)
			{
				if (!(tetro[i].array[j][k] == '#' ||
					tetro[i].array[j][k] == '.'))
					return (0);
			}
			ft_chr_replace(tetro[i].array[j], '#', tetro[i].id);
		}
	}
	return (1);
}
