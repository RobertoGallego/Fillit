/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_remove_piece.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmorgan- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/09 14:19:35 by pmorgan-          #+#    #+#             */
/*   Updated: 2019/01/13 14:26:41 by pmorgan-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void			add_piece(t_map *a_map, t_tetro *tetro, t_node pn)
{
	int		m;
	int		n;
	char	tmp;

	n = 0;
	while (tetro->tl.y + n <= tetro->br.y)
	{
		m = 0;
		while (tetro->tl.x + m <= tetro->br.x)
		{
			if (tetro->array[tetro->tl.y + n][tetro->tl.x + m] == tetro->id)
			{
				tmp = tetro->array[tetro->tl.y + n][tetro->tl.x + m];
				a_map->map[pn.y + n][pn.x + m] = tmp;
			}
			m++;
		}
		n++;
	}
}

void			remove_piece(t_map *a_map, t_tetro *tetro, t_node pn)
{
	int m;
	int n;

	n = 0;
	while (tetro->tl.y + n <= tetro->br.y)
	{
		m = 0;
		while (tetro->tl.x + m <= tetro->br.x)
		{
			if (tetro->array[tetro->tl.y + n][tetro->tl.x + m] == tetro->id)
				a_map->map[pn.y + n][pn.x + m] = '.';
			m++;
		}
		n++;
	}
}
