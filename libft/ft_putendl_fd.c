/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdos-san <sdos-san@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 08:58:31 by sdos-san          #+#    #+#             */
/*   Updated: 2022/08/10 11:02:50 by sdos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	size_t	pos;
	char	newline;

	newline = '\n';
	pos = 0;
	if (!s)
		return ;
	while (*(s + pos))
	{
		ft_putchar_fd(*(s + pos), fd);
		pos++;
	}
	ft_putchar_fd(newline, fd);
}
