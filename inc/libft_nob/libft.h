/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plandolf <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 09:38:53 by plandolf          #+#    #+#             */
/*   Updated: 2023/05/04 12:34:17 by plandolf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdbool.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

int		ft_isalpha(int c);
int		ft_isdigit(int c);
int		ft_isalnum(int c);
int		ft_atoi(const char *nptr);
int		ft_isascii(int c);
int		ft_isprint(int c);
size_t	ft_strlen(const char *s);
void	*ft_memset(void *s, int c, size_t n);
void	ft_bzero(void *s, size_t n);
size_t	ft_strlcat(char *dst, const char *src, size_t size);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	*ft_memmove(void *dest, const void *src, size_t n);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
int		ft_toupper(int c);
int		ft_tolower(int c);
char	*ft_strchr(const char *str, int c);
char	*ft_strrchr(const char *str, int c);
void	*ft_memchr(const void *str, int c, size_t n);
int		ft_memcmp(const void *str1, const void *str2, size_t n);
char	*ft_strnstr(const char *s1, const char *s2, size_t n);
int		ft_strncmp(const char *str1, const char *str2, size_t n);
void	*ft_calloc(size_t nmemb, size_t size);
char	*ft_strdup(const char *s);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strtrim(char const *s1, char const *set);
char	**ft_split(char const *s, char c);
char	*ft_itoa(int n);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void	ft_striteri(char *s, void (*f)(unsigned int, char*));
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
char	*ft_strjoin_get_next(char *s1, char *s2);
char	*ft_strchr_get_next(char *str, int c);
char	*ft_resume(char *s);
char	*ft_line(char *s);
char	*ft_read(int fd, char *s);
char	*get_next_line(int fd);
int		ft_printf(const char *str, ...);
int		ft_print_formats(va_list args, const char format);
// ft_printf_utils.c
int		ft_print_char(char c);
int		ft_print_str(char *s);
int		ft_print_nbr(long int i);
int		ft_number_lenght(long int i);
// ft_printf_utils_2.c
int		ft_hex_lenght(unsigned long int i);
void	ft_put_ptr(unsigned long int n);
int		ft_print_ptr(unsigned long int n);
int		ft_print_unsigned(unsigned int i);
// ft_printf_utils_3.c
void	ft_put_hex_lower(unsigned long int n);
int		ft_print_hex_lower(unsigned long int n);
void	ft_put_hex_upper(unsigned long int n);
int		ft_print_hex_upper(unsigned long int n);
// ft_itoa.c
char	*ft_itoa_printf(long int n);
void	ft_free_matrix(char **matrix);
char	*ft_trim(char *s1, char const *set);

#endif
