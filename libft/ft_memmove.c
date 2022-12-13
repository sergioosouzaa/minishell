/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdos-san <sdos-san@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 08:57:21 by sdos-san          #+#    #+#             */
/*   Updated: 2022/08/10 10:57:52 by sdos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	*copy_str_left(char *char_to, const char *char_from, size_t count)
{
	size_t	pos;

	pos = 0;
	while (pos < count)
	{
		*(char_to + pos) = *(char_from + pos);
		pos++;
	}
	return (char_to);
}

void	*ft_memmove(void *to, const void *from, size_t count)
{
	char		*char_to;
	const char	*char_from;
	size_t		pos;

	char_to = (char *)to;
	char_from = (const char *)from;
	if (count == 0)
		return (char_to);
	if (!char_from && !char_to && count > 0)
		return (char_to);
	if (to < from)
	{
		copy_str_left(char_to, char_from, count);
		return (char_to);
	}
	pos = count - 1;
	while (pos != 0)
	{
		*(char_to + pos) = *(char_from + pos);
		pos--;
	}
	*(char_to + pos) = *(char_from + pos);
	return (char_to);
}
