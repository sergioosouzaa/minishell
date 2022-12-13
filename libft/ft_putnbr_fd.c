/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdos-san <sdos-san@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 17:01:48 by sdos-san          #+#    #+#             */
/*   Updated: 2022/08/10 10:58:15 by sdos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	void	handle_negative(int fd)
{
	char	negative;

	negative = '-';
	write(fd, &negative, 1);
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

void	ft_putnbr_fd(int n, int fd)
{
	size_t	size;
	size_t	n_cpy;
	char	result;

	n_cpy = return_n(n);
	size = 1;
	if (n < 0)
		handle_negative(fd);
	while (n_cpy >= 10)
	{
		n_cpy = n_cpy / 10;
		size = size * 10;
	}
	n_cpy = return_n(n);
	while (size > 0)
	{
		result = (n_cpy / size) + '0';
		write(fd, &result, 1);
		n_cpy = n_cpy % size;
		size = size / 10;
	}
}
