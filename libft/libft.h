/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmorgan- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 12:59:47 by pmorgan-          #+#    #+#             */
/*   Updated: 2019/01/11 15:11:11 by pmorgan-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __LIBFT_H
# define __LIBFT_H

# include <stdlib.h>
# include <unistd.h>
# include <string.h>

typedef struct	s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}				t_list;

/*
**	ORIGINAL LIBFT FUNCTIONS
*/

int				ft_atoi(const char *str);
char			*ft_itoa(int nbr);

int				ft_isalpha(int c);
int				ft_isdigit(int c);
int				ft_isalnum(int c);
int				ft_isascii(int c);
int				ft_isprint(int c);

char			*ft_strcat(char *dest, const char *src);
int				ft_strcmp(const char *s1, const char *s2);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
char			*ft_strcpy(char *dest, const char *src);
char			*ft_strncpy(char *dest, const char *src, size_t n);
char			*ft_strdup(const char *src);
size_t			ft_strlcat(char *dest, const char *src, size_t size);
size_t			ft_strlen(const char *str);
char			*ft_strncat(char *dest, const char *src, size_t n);
char			*ft_strstr(const char *str, const char *to_find);
char			*ft_strchr(const char *s, int c);
char			*ft_strrev(char *str);
char			*ft_strrchr(const char *s, int c);
char			*ft_strnstr(const char *str, const char *to_find, size_t len);
char			*ft_strnew(size_t size);
void			ft_strdel(char **as);
void			ft_strclr(char *s);
void			ft_striter(char *s, void (*f)(char *));
void			ft_striteri(char *s, void (*f)(unsigned int, char *));
char			*ft_strmap(char const *s, char (*f)(char));
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int				ft_strequ(char const *s1, char const *s2);
int				ft_strnequ(char const *s1, char const *s2, size_t n);
char			*ft_strsub(char const *s, unsigned int start, size_t len);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strtrim(char const *s);
char			**ft_strsplit(char const *s, char c);

void			*ft_memset(void *b, int c, size_t len);
void			ft_bzero(void *b, size_t n);
void			*ft_memcpy(void *dst, const void *src, size_t n);
void			*ft_memccpy(void *dst, const void *src, int c, size_t n);
void			*ft_memmove(void *dst, const void *src, size_t len);
void			*ft_memchr(const void *s, int c, size_t n);
int				ft_memcmp(const void *s1, const void *s2, size_t n);
void			ft_memdel(void **as);
void			*ft_memalloc(size_t size);

void			ft_putchar_fd(char c, int fd);
void			ft_putchar(char c);
void			ft_putnbr_fd(int nb, int fd);
void			ft_putnbr(int nb);
void			ft_putstr_fd(const char *str, int fd);
void			ft_putstr(const char *str);

int				ft_toupper(int c);
int				ft_tolower(int c);

/*
**	ADDITIONAL FUNCTIONS
*/

char			*ft_strrev(char *str);
char			*ft_strnjoin(char const *s1, char const *s2, size_t n);
int				ft_minint(int n1, int n2);
int				ft_maxint(int n1, int n2);
char			*ft_strnchr(const char *s, int c, size_t n);
int				ft_strchr_ind(const char *s, int c);
int				ft_strnchr_ind(const char *s, int c, size_t n);
void			ft_ifstrdel(char **str_address);
int				ft_int_ifstrdel(char **str_address);
int				ft_minpositive(int n1, int n2);
char			*ft_strchr_range(const char *s, char low_bound, char up_bound);
void			ft_chr_replace(char *s, char current, char replacement);

#endif
