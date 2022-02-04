/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gborne <gborne@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 18:17:20 by gborne            #+#    #+#             */
/*   Updated: 2022/02/02 06:43:48 by gborne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H

# define LIBFT_H
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <stdarg.h>
# include <stdint.h>

# define BUFFER_SIZE	1024
# define INT_MAX		2147483647
# define INT_MIN		-2147483648

//		list related fonctions

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

t_list			*ft_lstnew(void *content);
void			ft_lstadd_front(t_list **lst, t_list *new);
int				ft_lstsize(t_list *lst);
t_list			*ft_lstlast(t_list *lst);
void			ft_lstadd_back(t_list **lst, t_list *new);
void			ft_lstdelone(t_list *lst, void (*del)(void *));
void			ft_lstclear(t_list **lst, void (*del)(void *));
void			ft_lstiter(t_list *lst, void (*f)(void *));
t_list			*ft_lstmap(t_list *lst, void *(*f)(void *),
					void (*del)(void *));

//		memory related fonctions

void			ft_bzero(void *s, size_t n);
void			*ft_calloc(size_t count, size_t size);
void			*ft_memchr(const void *s, int c, size_t n);
void			*ft_memcpy(void *dst, const void *src, size_t n);
void			*ft_memmove(void *dst, const void *src, size_t len);
void			*ft_memset(void *b, int c, size_t len);
int				ft_memcmp(const void *s1, const void *s2, size_t n);

//		character related fonctions

int				ft_isalnum(int c);
int				ft_isalpha(int c);
int				ft_isascii(int c);
int				ft_isdigit(int c);
int				ft_isprint(int c);
int				ft_tolower(int c);
int				ft_toupper(int c);

//		string related fonctions

void			ft_striteri(char *s, void (*f)(unsigned int, char*));
char			*ft_strchr(const char *s, int c);
char			*ft_strdup(const char *s1);
char			*ft_strjoin(char *s1, char const *s2);
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char			*ft_strnstr(const char *haystack, const char *needle,
					size_t len);
char			*ft_strrchr(const char *s, int c);
char			*ft_strtrim(char const *s1, char const *set);
char			*ft_substr(char const *s, unsigned int start, size_t len);
char			**ft_split(char const *s, char c);
char			*ft_itoa(int nb);
int				ft_atoi(const char *str);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
int 			ft_strcmp(const char *str1, const char *str2);
size_t			ft_strlcat(char *dst, const char *src, size_t dstsize);
size_t			ft_strlcpy(char *dst, const char *src, size_t dstsize);
unsigned long	ft_strlen(const char *s);
void			ft_putchar(char c);
void			ft_putnbr(int n);

//		file descriptor related fonctions

void			ft_putchar_fd(char c, int fd);
void			ft_putendl_fd(char *s, int fd);
void			ft_putnbr_fd(int n, int fd);
void			ft_putstr_fd(char *s, int fd);

//		ft_printf

int				ft_printf(const char *format, ...);
int				ft_putchar_printf(char c, int size);
int				ft_putstr_printf(char *s, int size);
int				ft_putnbr_printf(int n, int size);
int				ft_putunbr_printf(unsigned int n, int size);
int				ft_puthexa_printf(unsigned long n, char *base, int size);

//		get_next_line

char			*get_next_line(int fd);
char			*treat_mem(char *mem);
char			*treat_line(char *mem, char *line);
size_t			s_len(const char *s);
size_t			s_lcpy(char *dst, const char *src, size_t dstsize);
char			*s_chr(const char *s, int c, int next);
char			*s_ljoin(char *s1, char *s2, size_t s1_len, size_t s2_len);

#endif
