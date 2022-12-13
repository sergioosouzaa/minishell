/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdos-san <sdos-san@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 09:01:54 by sdos-san          #+#    #+#             */
/*   Updated: 2022/08/10 10:58:55 by sdos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*copyed_string;
	size_t	pos;
	size_t	string_size;

	pos = 0;
	string_size = ft_strlen(s);
	copyed_string = (char *)malloc(string_size + 1);
	if (!copyed_string)
		return (0);
	while (pos <= string_size)
	{
		*(copyed_string + pos) = *(s + pos);
		pos++;
	}
	return (copyed_string);
}
