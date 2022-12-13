/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdos-san < sdos-san@student.42.rio >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 09:06:35 by sdos-san          #+#    #+#             */
/*   Updated: 2022/08/22 16:51:48 by sdos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	string_size;
	size_t	pos;
	char	*ptr;
	size_t	pos_sub;

	pos = start;
	pos_sub = 0;
	string_size = len;
	if (!s)
		return (0);
	if (start > ft_strlen(s))
		string_size = 0;
	else if (len >= ft_strlen(s + start))
		string_size = ft_strlen(s + start);
	ptr = (char *)malloc(string_size + 1);
	if (!ptr)
		return (0);
	while (pos_sub < string_size)
	{
		*(ptr + pos_sub) = *(s + pos);
		pos++;
		pos_sub++;
	}
	*(ptr + pos_sub) = '\0';
	return (ptr);
}
