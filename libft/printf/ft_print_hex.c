/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdos-san < sdos-san@student.42.rio >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 09:59:13 by sdos-san          #+#    #+#             */
/*   Updated: 2022/08/24 18:22:04 by sdos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr(const char *txt)
{
	size_t	pos;
	char	*txt_null;

	txt_null = "(null)";
	pos = 0;
	if (txt == NULL)
	{
		while (*(txt_null + pos))
		{
			write(1, (txt_null + pos), 1);
			pos++;
		}
	}
	else
	{
		while (*(txt + pos))
		{
			ft_putchar(*(txt + pos));
			pos++;
		}
	}
	return (pos);
}

static int	return_free(char *ptr)
{
	free(ptr);
	return (0);
}

char	*malloc_string(size_t size)
{
	char	*ptr;
	size_t	pos;

	pos = 0;
	ptr = (char *)malloc(size);
	if (!ptr)
	{
		return_free(ptr);
		return (0);
	}
	while (pos < size - 1)
	{
		*(ptr + pos) = '0';
		pos++;
	}
	*(ptr + pos) = '\0';
	return (ptr);
}

int	ft_putpointer(void *ptr, char *characters)
{
	size_t			string_size;
	size_t			adress;
	char			*new_ptr;

	ft_putstr("0x");
	adress = (size_t)ptr;
	string_size = 1;
	while (adress > 15)
	{
		string_size++;
		adress = adress / 16;
	}
	new_ptr = malloc_string(string_size + 1);
	if (!new_ptr)
		return (return_free(new_ptr));
	adress = (size_t)ptr;
	while (adress != 0)
	{
		new_ptr[--string_size] = characters[adress % 16];
		adress = adress / 16;
	}
	adress = ft_putstr(new_ptr);
	free(new_ptr);
	return (adress + 2);
}

int	ft_puthex(unsigned int nbr, char *characters)

{
	int				string_size;
	size_t			nbr_cpy;
	char			*new_num;

	nbr_cpy = nbr;
	string_size = 1;
	while (nbr_cpy > 15)
	{
		string_size++;
		nbr_cpy = nbr_cpy / 16;
	}
	new_num = malloc_string(string_size + 1);
	if (!new_num)
		return (return_free(new_num));
	while (nbr != 0)
	{
		new_num[--string_size] = characters[nbr % 16];
		nbr = nbr / 16;
	}
	nbr = ft_putstr(new_num);
	free(new_num);
	return (nbr);
}
