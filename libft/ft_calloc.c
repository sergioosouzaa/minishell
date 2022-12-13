/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdos-san < sdos-san@student.42.rio >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 08:54:04 by sdos-san          #+#    #+#             */
/*   Updated: 2022/08/24 13:46:39 by sdos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;

	if (size * nmemb == 0)
	{
		ptr = (char *)malloc(1);
		return (ptr);
	}
	if (nmemb == SIZE_MAX || nmemb == SIZE_MAX)
		return (0);
	ptr = malloc(nmemb * size);
	if (!ptr)
		return (0);
	ft_memset(ptr, '\0', nmemb * size);
	return (ptr);
}
