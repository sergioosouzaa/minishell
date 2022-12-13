/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnums.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdos-san < sdos-san@student.42.rio >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 10:09:40 by sdos-san          #+#    #+#             */
/*   Updated: 2022/08/24 18:22:35 by sdos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	handle_negative(int fd)
{
	char	negative;

	negative = '-';
	write(fd, &negative, 1);
	return (1);
}

static size_t	return_n(int n)
{
	size_t	new_n;

	if (n < 0)
	{
		if (n == -2147483648)
			new_n = 2147483648;
		else
			new_n = (-1 * n);
	}
	else
		new_n = n;
	return (new_n);
}

int	ft_putnbr(int n)
{
	size_t	out_size;
	size_t	size;
	size_t	n_cpy;
	char	result;

	out_size = 0;
	n_cpy = return_n(n);
	size = 1;
	if (n < 0)
		out_size = handle_negative(1);
	while (n_cpy >= 10)
	{
		n_cpy = n_cpy / 10;
		size = size * 10;
	}
	n_cpy = return_n(n);
	while (size > 0)
	{
		result = (n_cpy / size) + '0';
		write(1, &result, 1);
		n_cpy = n_cpy % size;
		size = size / 10;
		out_size++;
	}
	return (out_size);
}

int	ft_putunsignednbr(unsigned int n)
{
	size_t	size;
	size_t	n_cpy;
	int		num_size;
	char	result;

	n_cpy = n;
	size = 1;
	num_size = 0;
	while (n_cpy >= 10)
	{
		n_cpy = n_cpy / 10;
		size = size * 10;
	}
	n_cpy = n;
	while (size > 0)
	{
		result = (n_cpy / size) + '0';
		write(1, &result, 1);
		n_cpy = n_cpy % size;
		num_size++;
		size = size / 10;
	}
	return (num_size);
}
