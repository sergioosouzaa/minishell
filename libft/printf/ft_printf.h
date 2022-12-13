/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdos-san < sdos-san@student.42.rio >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 10:10:06 by sdos-san          #+#    #+#             */
/*   Updated: 2022/08/24 18:23:10 by sdos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

int			ft_printf(const char *input, ...);
int			ft_putstr(const char *txt);
int			ft_putpointer(void *ptr, char *characters);
int			ft_puthex(unsigned int nbr, char *characters);
int			ft_putnbr(int n);
int			ft_putunsignednbr(unsigned int n);
int			ft_putchar(int ch);

#endif