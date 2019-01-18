/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: groberto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 13:57:22 by groberto          #+#    #+#             */
/*   Updated: 2019/01/14 15:42:17 by pmorgan-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int		ft_freetempo(char *tempo, int ret)
{
	free(tempo);
	return (ret);
}

static int		endline(char *buff)
{
	int			count;

	count = 0;
	while (buff[count] != '\n' && buff[count])
		count++;
	if (buff[count] == '\n')
	{
		buff[count] = '\0';
		return (count);
	}
	else
		return (-1);
}

static char		*mcpy(char *buff, char *tempo)
{
	size_t			i;
	size_t			j;
	char			*ptr;

	i = 0;
	j = 0;
	if (buff)
		i = ft_strlen(buff);
	if (tempo)
		j = ft_strlen(tempo);
	ptr = ft_strnew(i + j + 1);
	ft_memcpy(ptr, buff, i);
	ft_memcpy(ptr + i, tempo, j);
	ptr[i + j] = '\0';
	free(buff);
	return (ptr);
}

static int		check(char **buff, char **tempo, char **line)
{
	char			*ptr;
	int				lend;

	*buff = mcpy(*buff, *tempo);
	lend = endline(*buff);
	if (lend > -1)
	{
		*line = ft_strdup(*buff);
		ptr = *buff;
		*buff = ft_strdup(ptr + lend + 1);
		free(ptr);
		free(*tempo);
		return (1);
	}
	return (0);
}

int				get_next_line(const int fd, char **line)
{
	static char		*buff[BUFF_SIZE];
	char			*tempo;
	int				result;

	tempo = ft_strnew(BUFF_SIZE);
	if (!line || BUFF_SIZE <= 0 || fd < 0 || (read(fd, tempo, 0)) < 0)
		return (ft_freetempo(tempo, -1));
	while ((read(fd, tempo, BUFF_SIZE)) > 0)
	{
		result = check(&buff[fd], &tempo, line);
		if (result == 1)
			return (1);
		ft_memset(tempo, '\0', BUFF_SIZE);
	}
	if ((result = check(&buff[fd], &tempo, line)))
		return (1);
	if (ft_strlen(buff[fd]) > 0)
	{
		*line = ft_strdup(buff[fd]);
		ft_strdel(&buff[fd]);
		return (1);
	}
	free(tempo);
	return (0);
}
