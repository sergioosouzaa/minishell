/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdos-san < sdos-san@student.42.rio >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 09:05:00 by sdos-san          #+#    #+#             */
/*   Updated: 2022/08/22 16:51:28 by sdos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*function_return(const char *s1, const char *s2)
{
	if (!*(s2))
		return ((char *)(s1));
	return (0);
}

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t	pos_s1;
	size_t	pos_s2;
	size_t	point_s1;

	pos_s1 = 0;
	pos_s2 = 0;
	point_s1 = 0;
	while (pos_s1 < n && *(s1 + pos_s1) && *(s2 + pos_s2))
	{
		if (*(s1 + pos_s1) != *(s2 + pos_s2))
		{
			pos_s2 = 0;
			pos_s1 = point_s1 + 1;
			point_s1 = pos_s1;
		}
		if (*(s1 + pos_s1) == *(s2 + pos_s2) && pos_s1 < n)
		{
			pos_s2++;
			pos_s1++;
		}
	}
	return (function_return((s1 + point_s1), (s2 + pos_s2)));
}
