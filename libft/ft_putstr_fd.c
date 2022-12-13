/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdos-san <sdos-san@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 09:00:33 by sdos-san          #+#    #+#             */
/*   Updated: 2022/08/10 11:02:19 by sdos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	size_t	pos;

	pos = 0;
	if (!s)
		return ;
	while (*(s + pos))
	{
		ft_putchar_fd(*(s + pos), fd);
		pos++;
	}
}
