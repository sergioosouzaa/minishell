/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdos-san < sdos-san@student.42.rio >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 09:05:57 by sdos-san          #+#    #+#             */
/*   Updated: 2022/08/24 13:47:27 by sdos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	check_trim_char(char const *set, char s1)
{
	size_t	pos;

	pos = 0;
	while (*(set + pos) != '\0')
	{
		if (s1 == *(set + pos))
			return (0);
		pos++;
	}
	return (1);
}

static char	*return_free(void)
{
	char	*output_string;

	output_string = (char *)malloc(1);
	if (!output_string)
		return (0);
	*(output_string) = '\0';
	return (output_string);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	pos1;
	size_t	pos2;
	char	*output_string;

	if (!s1)
		return (0);
	pos1 = 0;
	pos2 = ft_strlen(s1) - 1;
	while (check_trim_char(set, *(s1 + pos1)) == 0 && pos1 < ft_strlen(s1))
		pos1++;
	while (check_trim_char(set, *(s1 + pos2)) == 0 && pos2 > 0)
		pos2--;
	if (pos1 > pos2 || (pos1 == 0 && pos2 == 0))
		return (return_free());
	output_string = ft_substr(s1, pos1, pos2 - pos1 + 1);
	if (!output_string)
		return (0);
	return (output_string);
}
