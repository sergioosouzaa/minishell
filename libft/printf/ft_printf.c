/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdos-san < sdos-san@student.42.rio >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 11:01:16 by sdos-san          #+#    #+#             */
/*   Updated: 2022/08/24 18:22:20 by sdos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(int ch)
{
	unsigned char	c;

	c = (unsigned char)ch;
	write(1, &c, 1);
	return (1);
}

static int	handle_percent(char var_type, va_list ptr)
{
	if (var_type == 'c')
		return (ft_putchar(va_arg(ptr, int)));
	else if (var_type == 's')
		return (ft_putstr(va_arg(ptr, char *)));
	else if (var_type == 'p')
		return (ft_putpointer(va_arg(ptr, void *), "0123456789abcdef"));
	else if (var_type == 'd' || var_type == 'i')
		return (ft_putnbr(va_arg(ptr, int)));
	else if (var_type == 'u')
		return (ft_putunsignednbr(va_arg(ptr, unsigned int)));
	else if (var_type == 'x')
		return (ft_puthex(va_arg(ptr, unsigned int), "0123456789abcdef"));
	else if (var_type == 'X')
		return (ft_puthex(va_arg(ptr, unsigned int), "0123456789ABCDEF"));
	else if (var_type == '%')
		return (ft_putchar('%'));
	return (0);
}

int	ft_printf(const char *input, ...)
{
	size_t	pos;
	size_t	size;
	va_list	ptr;

	va_start(ptr, input);
	size = 0;
	pos = 0;
	while (*(input + pos))
	{
		if (*(input + pos) == '%')
		{
			size = size + handle_percent(*(input + pos + 1), ptr);
			pos = pos + 2;
		}
		else
		{
			size = size + ft_putchar(*(input + pos));
			pos++;
		}
	}
	va_end(ptr);
	return (size);
}
