/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdos-san <sdos-san@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 09:03:08 by sdos-san          #+#    #+#             */
/*   Updated: 2022/08/10 10:59:20 by sdos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	pos;
	size_t	size_output;

	pos = 0;
	while (*dst && pos < size)
	{
		++dst;
		++pos;
	}
	size_output = ft_strlcpy(dst, src, size - pos);
	return (size_output + pos);
}
