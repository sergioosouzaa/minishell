/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdos-san <sdos-san@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 09:01:27 by sdos-san          #+#    #+#             */
/*   Updated: 2022/08/10 10:58:33 by sdos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**malloc_array(char const *s, char c)
{
	size_t	size;
	size_t	pos;
	size_t	check_div;
	char	**ptr;

	size = 0;
	pos = 0;
	check_div = 1;
	while (*(s + pos))
	{
		if (check_div == 1 && *(s + pos) != c)
		{
			check_div = 0;
			size++;
		}
		else if (*(s + pos) == c)
			check_div = 1;
		pos++;
	}
	ptr = (char **)malloc(sizeof(char **) * (size + 1));
	if (!ptr)
		return (0);
	ptr[size] = 0;
	return (ptr);
}

static char	*malloc_strings(char const *s, char c)
{
	size_t	size;
	size_t	pos_s;
	char	*ptr;

	size = 0;
	pos_s = 0;
	while (*(s + pos_s))
	{
		if (*(s + pos_s) != c)
			size++;
		else if (*(s + pos_s) == c && size > 0)
		{
			ptr = (char *)malloc(size + 1);
			ft_strlcpy(ptr, s, size + 1);
			return (ptr);
		}
		pos_s++;
	}
	ptr = (char *)malloc(size + 1);
	if (!ptr)
		return (0);
	ft_strlcpy(ptr, s, size + 1);
	return (ptr);
}

char	**ft_split(char const *s, char c)
{
	char	**str_array;
	size_t	pos_array;
	size_t	pos_s;

	pos_s = 0;
	pos_array = 0;
	if (!s)
		return (0);
	str_array = malloc_array(s, c);
	if (!str_array)
		return (0);
	while (*(s + pos_s))
	{
		if (*(s + pos_s) != c)
		{
			*(str_array + pos_array) = malloc_strings(s + pos_s, c);
			pos_s = pos_s + ft_strlen(*(str_array + pos_array));
			pos_array++;
		}
		else
			pos_s++;
	}
	return (str_array);
}
