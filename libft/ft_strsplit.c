/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit_v4.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmorgan- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 10:32:29 by pmorgan-          #+#    #+#             */
/*   Updated: 2018/12/03 14:43:22 by pmorgan-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(char const *s, char c)
{
	int	i;
	int	j;
	int	word_count;

	i = 0;
	j = 0;
	word_count = 0;
	while (s[j])
	{
		while (s[i] == c && s[j])
		{
			i++;
			j = i;
		}
		while (s[j] != c && s[j])
			j++;
		if (j > i)
		{
			word_count++;
			i = j;
		}
	}
	return (word_count);
}

static void	increment_indices(int *i, int *j, const char *s, char c)
{
	while (s[*i] == c && s[*j])
	{
		(*i)++;
		*j = *i;
	}
	while (s[*j] != c && s[*j])
		(*j)++;
	return ;
}

static int	*word_len(char const *s, char c, int word_num)
{
	int *ind;
	int i;
	int	j;

	if (!(ind = (int*)ft_memalloc(2 * sizeof(int))))
		return (NULL);
	i = 0;
	j = 0;
	while (s[j])
	{
		increment_indices(&i, &j, s, c);
		if (j > i)
		{
			word_num--;
			if (word_num == 0)
			{
				ind[0] = i;
				ind[1] = j;
				return (ind);
			}
			i = j;
		}
	}
	return (0);
}

static char	*populate_array(const char *s, int indices[2])
{
	char	*string;
	size_t	i;

	if (!(string = (char*)ft_memalloc((indices[1] - indices[0] + 1))))
		return (NULL);
	i = 0;
	while (indices[0] < indices[1])
		string[i++] = s[indices[0]++];
	string[indices[0]] = '\0';
	return (string);
}

char		**ft_strsplit(char const *s, char c)
{
	int		n_words;
	char	**array;
	int		i;
	int		indices[2];

	if (!s)
		return (NULL);
	n_words = count_words(s, c);
	if (!(array = (char**)ft_memalloc((n_words + 1) * sizeof(char*))))
		return (NULL);
	i = 1;
	while (i <= n_words)
	{
		indices[0] = (word_len(s, c, i))[0];
		indices[1] = (word_len(s, c, i))[1];
		array[i - 1] = populate_array(s, indices);
		if (!array[i - 1])
			return (NULL);
		i++;
	}
	array[n_words] = 0;
	return (array);
}
