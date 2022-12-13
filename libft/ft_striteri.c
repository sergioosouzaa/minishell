/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdos-san <sdos-san@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 09:02:06 by sdos-san          #+#    #+#             */
/*   Updated: 2022/08/10 10:59:01 by sdos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	pos;
	size_t			size;

	if (!s || !f)
		return ;
	size = ft_strlen(s);
	pos = 0;
	while (size > 0)
	{
		f(pos, (s + pos));
		pos++;
		size--;
	}
}
