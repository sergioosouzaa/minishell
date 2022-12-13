/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdos-san < sdos-san@student.42.rio >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 08:45:56 by sdos-san          #+#    #+#             */
/*   Updated: 2022/09/28 13:37:33 by sdos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_iswhitespace(int ch)
{
	return ((ch >= 9 && ch <= 13) || ch == 32);
}

static void	return_error(void)
{
	write(1, "ERROR\n", 6);
	exit (0);
}

long int	ft_atoi(const char *str)
{
	unsigned int	pos;
	long int		output;
	int				sign;

	output = 0;
	sign = 1;
	pos = 0;
	while (ft_iswhitespace(*(str + pos)))
		pos++;
	if (*(str + pos) == '-')
	{
		sign = -1;
		pos++;
	}
	else if (*(str + pos) == '+')
		pos++;
	while (*(str + pos) && ft_isdigit(*(str + pos)))
	{
		output = (output * 10) + (*(str + pos) - '0');
		pos++;
	}
	if ((output * sign) > 2147483647 || (output * sign) < -2147483648)
		return_error();
	return (output * sign);
}
