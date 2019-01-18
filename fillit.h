/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmorgan- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/04 15:49:53 by pmorgan-          #+#    #+#             */
/*   Updated: 2019/01/14 12:44:05 by pmorgan-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __FILLIT_H
# define __FILLIT_H

# include <stdlib.h>
# include <fcntl.h>
# include "./libft/libft.h"
# include "get_next_line.h"

typedef struct	s_node
{
	int		y;
	int		x;
}				t_node;

/*
**	br = bottom right node of the tetro within [4][4] array.
**	tl = top left
**	pn = present node in map
*/

typedef struct	s_tetro
{
	char	**array;
	char	id;
	t_node	tl;
	t_node	br;
}				t_tetro;

typedef struct	s_map
{
	char	**map;
	t_node	pn;
	int		dim;
}				t_map;

int				find_right_edge(t_tetro tetro);
int				find_left_edge(t_tetro tetro);
int				find_top_bottom(t_tetro tetro, _Bool top);
int				sqrt_up(int n);
_Bool			new_map(t_map *a_map, int dim);
_Bool			retrieve_tetro_array(t_tetro *tetro);
_Bool			grow_map(t_map *a_map, t_tetro *tetro);
_Bool			recursive_fit(t_map *a_map, t_tetro *tetro, size_t id);
void			print_tetro_array(t_tetro *tetro, int num_tetri);
void			print_map(t_map *a_map);
void			free_map(t_map *a_map, int dim);
void			add_piece(t_map *a_map, t_tetro *tetro, t_node pn);
void			remove_piece(t_map *a_map, t_tetro *tetro, t_node pn);
void			free_tetros(t_tetro *tetro);
t_tetro			*recover_tetros(char *filename, int *num_tetri);
long			error_msg(void);
int				check_shape_y_axis(t_tetro *tetro);
int				check_shape_x_axis(t_tetro *tetro);
_Bool			count_hashtags(t_tetro *tetro);
_Bool			count_tetros(char *filename, int *num_tetri);
_Bool			check_tetro_chars(t_tetro *tetro, int num_tetri);

#endif
