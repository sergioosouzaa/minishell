/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thsousa <thsousa@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 14:56:21 by thsousa           #+#    #+#             */
/*   Updated: 2023/01/23 14:56:23 by thsousa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*count;

	count = 0;
	while (*s)
	{
		if (*s == (char)c)
			count = (char *)s;
		s++;
	}
	if (c == 0)
		return ((char *)s);
	return (count);
}
