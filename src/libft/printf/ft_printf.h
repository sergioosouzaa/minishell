/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thsousa <thsousa@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 14:43:20 by thsousa           #+#    #+#             */
/*   Updated: 2022/06/30 14:43:23 by thsousa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

int		ft_printf(const char *str, ...);
size_t	ft_count_u(unsigned int n);
int		put_utoa(unsigned int i);
int		put_hexa(unsigned int i);
int		put_hexa_up(unsigned int i);
int		count_hexa(unsigned long i);
size_t	ft_count(int i);
char	*ft_numb(char *str, unsigned int i, size_t n_len);
size_t	ft_strlen(const char *str);
int		put_char(char c);
int		put_str(char *s);
int		put_ptr(unsigned long i);
int		put_itoa(int i);
char	*ft_find(const char *s, int c);
char	*ft_numb_h(char *str, int i, size_t n_len);
#endif
