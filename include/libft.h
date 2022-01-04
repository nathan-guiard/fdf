/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nguiard <nguiard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 14:54:18 by nguiard           #+#    #+#             */
/*   Updated: 2022/01/04 03:00:35 by nguiard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

/* Chars */
int		ft_isalpha(int c);
int		ft_isdigit(int c);
int		ft_isalnum(int c);
int		ft_isascii(int c);
int		ft_isprint(int c);
char	ft_toupper(int c);
char	ft_tolower(int c);

/* Strings */
size_t	ft_strlen(const char *s);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
size_t	ft_strlcat(char *dst, const char *src, size_t size);
char	*ft_strchr(const char *s, int c);
char	*ft_strrchr(const char *s, int c);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strnstr(const char *big, const char *little, size_t len);
int		ft_atoi(const char *nptr);

/* Memoire */
void	*ft_memset(void *s, int c, size_t n);
void	ft_bzero(void *s, size_t n);
void	*ft_memcpy(void *dst, const void *src, size_t n);
void	*ft_memmove(void *dst, const void *src, size_t len);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
void	*ft_memchr(const void *s, int c, size_t n);

/* Malloc */
void	*ft_calloc(size_t nmemb, size_t size);
char	*ft_strdup(const char *s);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strtrim(char const *s1, char const *set);
char	**ft_split(char const *s, char c);
char	*ft_itoa(int n);

/* Pointeur sur fonction */
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void	ft_striteri(char *s, void (*f)(unsigned int, char*));

/* fd */
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);

/* Bonus */
t_list	*ft_lstnew(void *content);
void	ft_lstadd_front(t_list **alst, t_list *new);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **alst, t_list *new);
void	ft_lstdelone(t_list *lst, void (*del)(void*));
void	ft_lstclear(t_list **clear, void (*del)(void *));
void	ft_lstiter(t_list *lst, void (*f)(void *));
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

/* get_next_line */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define FD_MAX 1024
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>

/* get_next_line */
char	*get_next_line(int fd);
char	*get_line(char *s, int i);
char	*new_rest(char *rest);
char	*read_until_newline(int fd, char *rest);
char	*the_line(char *s);

/* Utils */
char	*ft_strjoin_g(char *s1, char *s2);
char	*ft_strchr_g(const char *s, int c);
char	*join(char *rest, char *buff);

#endif

/* ft_printf */
#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>
# include <limits.h>

/* Enum t_type */
typedef enum e_type
{
	rien = 0,
	nombre = 1,
	caractere = 2,
	non_signe = 3,
	pointeur = 4,
	hex_min = 5,
	hex_maj = 6,
	pourcent = 7,
	chaine = 8,
}	t_type;

/* Variables */
# define HEX_MIN "0123456789abcdef"
# define HEX_MAJ "0123456789ABCDEF"
# define DEC "0123456789"
# define TYPES "cspdiuxX%"

/* Parsing */
t_type	*parsing(const char *s);
t_type	is_valid(char c);

/* Print arguments */
int		count_putstr(char *s);
int		count_putchar(char c);
int		count_putunsigned(unsigned int n);
int		count_puthex_min(unsigned int n);
int		count_puthex_maj(unsigned int n);
int		count_putprct(void);
int		count_putnbr(int n);
int		count_putptr(void *n);

/* PRINTF */
int		ft_printf(const char *s, ...);
#endif

#endif
