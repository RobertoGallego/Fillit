/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmorgan- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/03 15:29:30 by pmorgan-          #+#    #+#             */
/*   Updated: 2019/01/17 12:23:24 by pmorgan-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

long			error_msg(void)
{
	ft_putstr("error\n");
	return (0);
}

int				main(int argc, char **argv)
{
	t_map	*a_map;
	t_tetro	*tetro;
	int		dim;
	int		num_tetri;

	if (argc != 2)
	{
		ft_putstr("usage: ./fillit input_file\n");
		return (1);
	}
	if (!(tetro = recover_tetros(argv[1], &num_tetri)))
		return (1);
	dim = sqrt_up(num_tetri * 4);
	if (!(a_map = (t_map*)malloc(sizeof(t_map))))
		return (1);
	if (!(new_map(a_map, dim)))
		return (1);
	grow_map(a_map, tetro);
	free(a_map);
	return (0);
}

static _Bool	collision(t_map *a_map, t_tetro *tetro, t_node pn)
{
	int	n;
	int	m;

	n = -1;
	while (tetro->tl.y + (++n) < 4)
	{
		m = -1;
		while (tetro->tl.x + (++m) < 4)
			if (tetro->array[tetro->tl.y + n][tetro->tl.x + m] != '.'
				&& a_map->map[pn.y + n][pn.x + m] != '.')
				return (1);
	}
	return (0);
}

_Bool			grow_map(t_map *a_map, t_tetro *tetro)
{
	int	dim;

	while (!recursive_fit(a_map, tetro, 0))
	{
		dim = a_map->dim;
		free_map(a_map, dim);
		if (!(new_map(a_map, ++dim)))
			return (0);
	}
	print_map(a_map);
	dim = a_map->dim;
	free_map(a_map, dim);
	free_tetros(tetro);
	return (1);
}

_Bool			recursive_fit(t_map *a_map, t_tetro *tetro, size_t ind)
{
	t_node	pn;

	if (tetro[ind].array == NULL)
		return (1);
	pn.y = 0;
	while (pn.y + tetro[ind].br.y - tetro[ind].tl.y < a_map->dim)
	{
		pn.x = 0;
		while (pn.x + tetro[ind].br.x - tetro[ind].tl.x < a_map->dim)
		{
			if (!collision(a_map, &tetro[ind], pn))
			{
				add_piece(a_map, &tetro[ind], pn);
				if (recursive_fit(a_map, tetro, ind + 1))
					return (1);
				remove_piece(a_map, &tetro[ind], pn);
			}
			pn.x++;
		}
		pn.y++;
	}
	return (0);
}
