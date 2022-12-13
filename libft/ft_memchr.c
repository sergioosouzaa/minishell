/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdos-san <sdos-san@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 08:56:20 by sdos-san          #+#    #+#             */
/*   Updated: 2022/08/10 11:00:00 by sdos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *buffer, int ch, size_t count)
{
	size_t	pos;
	char	*string_buffer;

	string_buffer = (char *)buffer;
	pos = 0;
	ch = ch % 256;
	while (pos < count)
	{
		if (*(string_buffer + pos) == ch)
			return (string_buffer + pos);
		pos++;
	}
	return ((void *)0);
}
