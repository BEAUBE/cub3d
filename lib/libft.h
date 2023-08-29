/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slepetit <slepetit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 13:54:56 by slepetit          #+#    #+#             */
/*   Updated: 2023/08/29 05:49:06 by slepetit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <fcntl.h>
# include <string.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

# define BUFFER_SIZE 1

int		ft_isalpha(int c);
int		ft_isdigit(int c);
int		ft_isalnum(int c);
int		ft_isascii(int c);
int		ft_isprint(int c);
int		ft_toupper(int c);
int		ft_tolower(int c);
int		ft_strcmp(char *s1, char *s2);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
int		ft_atoi(const char *nptr);
size_t	ft_strlen(const char *s);
size_t	ft_strlcat(char *dst, const char *src, size_t size);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
void	*ft_memset(void *s, int c, size_t n);
void	ft_striteri(char *s, void (*f)(unsigned int, char*));
void	ft_bzero(void *s, size_t n);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	*ft_memchr(const void *s, int c, size_t n);
void	ft_putchar_fd(char c, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putstr_fd(char *s, int fd);
void	*ft_calloc(size_t nmemb, size_t size);
void	ft_putnbr_fd(int n, int fd);
void	*ft_memmove(void *dest, const void *src, size_t n);
char	*ft_strchr(const char *s, int c);
char	*ft_strrchr(const char *s, int c);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_fill(char *str, int fd);
char	*ft_strjoin(char *s1, const char *s2);
char	*ft_strtrim(char const *s1, char const *set);
char	**ft_split(char *s, char c);
char	*ft_strnstr(const char *big, const char *little, size_t len);
char	*ft_itoa(int n);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char	*ft_strdup(const char *s);
size_t	ft_putchar(char c);
void	ft_putnbr(int n);
size_t	ft_putstr(char *s);

//GET_NEXT_LINE
size_t	ft_nl(char *str);
char	*ft_strjoin_gnl(char *s1, char *s2);
char	*ft_substr_gnl(char *str, unsigned int start, size_t len);
char	*get_next_line(int fd);
//PRINTF
size_t	ft_putnbr_printf(long int nb);
size_t	ft_puthexa(unsigned long int nb, char *base);
size_t	ft_putptr(unsigned long ptr);
size_t	ft_putu(unsigned long long nb, char *base);
size_t	ft_type(char type, va_list li);
int		ft_check_s(va_list li);
int		ft_check_p(va_list li);
int		ft_printf(const char *type, ...);

#endif
