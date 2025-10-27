/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaida <lgaida@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 20:53:33 by lgaida            #+#    #+#             */
/*   Updated: 2025/10/22 17:28:06 by lgaida           ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#ifndef LIBFT_H
# define LIBFT_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <stdarg.h>
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

// OG libft
int		ft_atoi(const char *nptr);
void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t nmemb, size_t size);
int		ft_isalnum(int c);
int		ft_isalpha(int c);
int		ft_isascii(int c);
int		ft_isdigit(int c);
int		ft_isprint(int c);
char	*ft_itoa(int n);
void	*ft_memchr(const void *s, int c, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	*ft_memmove(void *dest, const void *src, size_t n);
void	*ft_memset(void *s, int c, size_t n);
void	ft_putchar_fd(char c, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
void	ft_putstr_fd(char *s, int fd);
char	**ft_split(char const *s, char c);
char	*ft_strchr(const char *s, int c);
char	*ft_strdup(const char *s);
void	ft_striteri(char *s, void (*f)(unsigned int, char*));
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlcat(char *dst, const char *src, size_t size);
size_t	ft_strlcpy(char *dest, const char *src, size_t size);
size_t	ft_strlen(const char *s);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strnstr(const char *big, const char *little, size_t len);
char	*ft_strrchr(const char *s, int c);
char	*ft_strtrim(char const *s1, char const *set);
char	*ft_substr(char const *s, unsigned int start, size_t len);
int		ft_tolower(int c);
int		ft_toupper(int c);

// ft_printf
int		ft_printf(const char *str, ...);
int		ft_handle_args(char spec, va_list *args);
int		ft_print_char(va_list *args);
int		ft_print_str(va_list *args);
int		ft_print_addr(va_list *args);
int		ft_print_int(va_list *args);
int		ft_print_uint(va_list *args);
int		ft_print_lowhex(va_list *args);
int		ft_print_uphex(va_list *args);

// get_next_line
char	*get_next_line(int fd);
void	read_from_fd(int fd, char **stash, int *panic_button);
void	extract_line(char **stash, char **line, int *panic_button);
char	*gnl_strdup(char *str, int *panic_button);
char	*gnl_strjoin(char *str1, char *str2, int *panic_button);
char	*gnl_substr(char *str, char start, char end, int *panic_button);

// add-ons
int		ft_atoi_base(char *str, char *base);
int		ft_iofc(char *str, char c);
size_t	ft_count_entries(char const *s, char c);

#endif
