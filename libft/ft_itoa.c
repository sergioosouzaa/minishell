/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdos-san < sdos-san@student.42.rio >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 08:55:45 by sdos-san          #+#    #+#             */
/*   Updated: 2022/08/24 13:46:48 by sdos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	check_size(int n)
{
	size_t	size;

	size = 1;
	if (n <= 0)
		size++;
	while (n != 0)
	{
		size++;
		n = n / 10;
	}
	return (size);
}

char	*ft_itoa(int n)
{
	char	*converted_num;
	size_t	size;
	int		sign;

	sign = 1;
	size = check_size(n) - 1;
	converted_num = malloc(check_size(n));
	if (!converted_num)
		return (0);
	if (n < 0)
	{
		*(converted_num) = '-';
		sign = -1;
	}
	converted_num[size] = '\0';
	size--;
	*(converted_num + size) = '0';
	while (n != 0)
	{
		*(converted_num + size) = (sign * (n % 10)) + '0';
		n = n / 10;
		size--;
	}
	return (converted_num);
}
