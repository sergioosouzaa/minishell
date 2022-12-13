/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdos-san < sdos-san@student.42.rio >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 09:04:41 by sdos-san          #+#    #+#             */
/*   Updated: 2022/08/22 16:51:22 by sdos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *str1, const char *str2, size_t count)
{
	size_t	pos;

	pos = 0;
	while (pos < count && *(str1 + pos) && *(str2 + pos))
	{
		if (*(str1 + pos) != *(str2 + pos))
			break ;
		pos++;
	}
	if (count == 0)
		return (0);
	if (pos == count)
		pos--;
	return (((unsigned char)*(str1 + pos) - (unsigned char)*(str2 + pos)));
}
