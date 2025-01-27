/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vflores <vflores@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 18:25:18 by vflores           #+#    #+#             */
/*   Updated: 2025/01/14 16:33:37 by vflores          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//libft
#ifndef LIBFT_H
# define LIBFT_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif
# include <stddef.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>
// #ifndef GET_NEXT_LINE_H
// # define GET_NEXT_LINE_H


# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>

// 1er partie
int		ft_isalpha(int c);
int		ft_isdigit(int c);
int		ft_isalnum(int c);
int		ft_isascii(int c);
int		ft_isprint(int c);
size_t	ft_strlen(const char *s);
void	*ft_memset(void *b, int c, size_t len);
void	ft_bzero(void *s, size_t n);
void	*ft_memcpy(void *dst, const void *src, size_t n);
void	*ft_memmove(void *dst, const void *src, size_t n);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);
int		ft_toupper(int c);
int		ft_tolower(int c);
char	*ft_strchr(const char *s, int c);
char	*ft_strrchr(const char *s, int c);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	*ft_memchr(const void *s, int c, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
char	*ft_strnstr(const char *big, const char *little, size_t len);
void	*ft_calloc(size_t count, size_t size);
char	*ft_strdup(const char *s1);
int		ft_atoi(const char *str);

//2me partie
char	*ft_substr(const char *s, unsigned int start, size_t len);
char	*ft_strjoin(const char *s1, const char *s2);
char	*ft_strtrim(char const *s1, char const *set);
char	**ft_split(const char *s, char c);
char	*ft_itoa(int n);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void	ft_striteri(char *s, void (*f)(unsigned int, char *));
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);

//bonus
typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

t_list	*ft_lstnew(void *content);
void	ft_lstadd_front(t_list **lst, t_list *new);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstdelone(t_list *lst, void (*del)(void *));
void	ft_lstclear(t_list **lst, void (*del)(void *));
void	ft_lstiter(t_list *lst, void (*f)(void *));
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

//printf
int		ft_printf(const char *input, ...);
int		check_type(va_list args, const char input);
int		ft_print_char(int c);
int		ft_print_str(char *str);
int		ft_print_ptr(unsigned long long ptr);
int		ft_print_nbr(int n);
int		ft_print_unsigned(unsigned int n);
int		ft_print_hex(unsigned int num, const char input);
int		ft_print_percent(void);

void	ft_putchar(char c);
void	ft_putnbr_base(unsigned long long nbr, char *base);

int		ft_ptr_len(unsigned long num);
int		ft_num_len(unsigned	int num);
void	ft_put_hex(unsigned int num, const char input);
int		ft_hex_len(unsigned	int num);

//gnl
// char	*ft_strdup(const char *s);
// size_t	ft_strlen(const char *s);
// char	*ft_substr(char const *s, unsigned int start, size_t len);
// char	*ft_strcat(char *dest, char *src);
// char	*ft_strjoin(char const *s1, char const *s2);
char	*get_next_line(int fd);
//no se declaran las funciones estaticas

#endif


// // printf

// #ifndef FT_PRINTF_H
// # define FT_PRINTF_H

// # include <stdarg.h>
// # include <unistd.h>

// int		ft_printf(const char *input, ...);
// int		check_type(va_list args, const char input);
// int		ft_print_char(int c);
// int		ft_print_str(char *str);
// int		ft_print_ptr(unsigned long long ptr);
// int		ft_print_nbr(int n);
// int		ft_print_unsigned(unsigned int n);
// int		ft_print_hex(unsigned int num, const char input);
// int		ft_print_percent(void);

// void	ft_putchar(char c);
// void	ft_putnbr_base(unsigned long long nbr, char *base);

// int		ft_ptr_len(unsigned long num);
// int		ft_num_len(unsigned	int num);
// void	ft_put_hex(unsigned int num, const char input);
// int		ft_hex_len(unsigned	int num);

// #endif

// //gnl
// #ifndef GET_NEXT_LINE_H
// # define GET_NEXT_LINE_H
// # ifndef BUFFER_SIZE
// #  define BUFFER_SIZE 42
// # endif

// # include <stdlib.h>
// # include <fcntl.h>
// # include <unistd.h>

// char	*ft_strdup(const char *s);
// size_t	ft_strlen(const char *s);
// char	*ft_substr(char const *s, unsigned int start, size_t len);
// char	*ft_strcat(char *dest, char *src);
// char	*ft_strjoin(char const *s1, char const *s2);
// // char	*ft_strchr(const char *s, int c);
// char	*get_next_line(int fd);

// char	*get_next_line(int fd);
// //no se declaran las funciones estaticas
// #endif
