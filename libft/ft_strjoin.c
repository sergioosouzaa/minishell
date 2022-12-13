/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdos-san <sdos-san@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 09:02:36 by sdos-san          #+#    #+#             */
/*   Updated: 2022/08/10 10:59:08 by sdos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	copy_str(char *new_str, char const *s)
{
	size_t	pos;

	pos = 0;
	while (*(s + pos))
	{
		*(new_str + pos) = *(s + pos);
		pos++;
	}
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new_string;
	size_t	string_size;

	if (!s1 || !s2)
		return (0);
	string_size = 1 + ft_strlen(s1) + ft_strlen(s2);
	new_string = (char *)malloc(string_size);
	if (!new_string)
		return (0);
	copy_str(new_string, s1);
	copy_str(new_string + ft_strlen(s1), s2);
	*(new_string + ft_strlen(s1) + ft_strlen(s2)) = '\0';
	return (new_string);
}
