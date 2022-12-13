/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdos-san <sdos-san@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 09:07:43 by sdos-san          #+#    #+#             */
/*   Updated: 2022/10/12 13:28:48 by sdos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

/* ********************************************************************* */
/* ********************************INCLUDES***************************** */
/* ********************************************************************* */

# include <stdlib.h>
# include <stdint.h>
# include <unistd.h>
# include "./printf/ft_printf.h"

/* ********************************************************************* */
/* **********************FUNCTIONS PROTOTYPES*************************** */
/* ********************************************************************* */

/* **********************************IS********************************* */
int			ft_isalpha(int ch);
int			ft_isdigit(int ch);
int			ft_isalnum(int ch);
int			ft_isascii(int ch);
int			ft_isprint(int ch);

/* **********************************TO******************************** */
int			ft_tolower(int ch);
int			ft_toupper(int ch);

/* **********************************STR****************************** */
size_t		ft_strlen(const char *str);
char		*ft_strchr(const char *str, int c);
char		*ft_strrchr(const char *str, int ch);
int			ft_strncmp(const char *str1, const char *str2, size_t count);
size_t		ft_strlcpy(char *dst, const char *src, size_t size);
size_t		ft_strlcat(char *dst, const char *src, size_t size);
char		*ft_strnstr(const char *s1, const char *s2, size_t n);

/* **********************************MEM****************************** */
void		*ft_memset(void *buf, int ch, size_t count);
void		*ft_memchr(const void *buffer, int ch, size_t count);
int			ft_memcmp(const void *buf1, const void *buf2, size_t count);
void		*ft_memcpy(void *to, const void *from, size_t count);
void		*ft_memmove(void *to, const void *from, size_t count);
void		ft_bzero(void *s, size_t n);

/* **********************************ATOI******************************* */
long int	ft_atoi(const char *str);

/* **********************************MALLOC***************************** */
void		*ft_calloc(size_t nmemb, size_t size);
char		*ft_strdup(const char *s);

/* **********************************PART II************************ */
char		*ft_substr(char const *s, unsigned int start, size_t len);
char		*ft_strjoin(char const *s1, char const *s2);
char		*ft_strtrim(char const *s1, char const *set);
char		**ft_split(char const *s, char c);
char		*ft_itoa(int n);
char		*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void		ft_striteri(char *s, void (*f)(unsigned int, char*));
void		ft_putchar_fd(char c, int fd);
void		ft_putstr_fd(char *s, int fd);
void		ft_putendl_fd(char *s, int fd);
void		ft_putnbr_fd(int n, int fd);

#endif