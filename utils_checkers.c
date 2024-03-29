/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_checkers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thsousa <thsousa@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 15:05:55 by thsousa           #+#    #+#             */
/*   Updated: 2023/01/23 15:05:56 by thsousa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_isspace(char c)
{
	if ((c >= 9 && c <= 13) || c == ' ')
		return (1);
	return (0);
}

int	ft_ismetachar(char c)
{
	if (c >= 7 && c <= 13)
		return (1);
	if (c >= 33 && c <= 47)
		return (1);
	if (c >= 57 && c <= 64)
		return (1);
	if (c >= 91 && c <= 96)
		return (1);
	if (c >= 123 && c <= 126)
		return (1);
	return (0);
}

int	has_output(char *cmd)
{
	if (!ft_strncmp(cmd, "pwd", 3) && ft_strlen(cmd) == 3)
		return (1);
	else if (!ft_strncmp(cmd, "env", 3) && ft_strlen(cmd) == 3)
		return (1);
	else if (!ft_strncmp(cmd, "echo", 4) && ft_strlen(cmd) == 4)
		return (1);
	return (0);
}

int	check_pipe(t_sh *cmd)
{
	char	*tmp;

	tmp = ft_strtrim(cmd->prompt, " ");
	if (tmp[0] == '|' || tmp[ft_strlen(tmp) - 1] == '|')
	{
		ft_perror(2, NULL, PIPE);
		ft_free(&tmp);
		return (1);
	}
	ft_free(&tmp);
	return (0);
}

int	check_quote(char *input)
{
	int	i;
	int	d_quote;
	int	s_quote;

	d_quote = 0;
	s_quote = 0;
	i = 0;
	while (input[i])
	{
		if (input[i] == 39 && !s_quote && !d_quote)
			s_quote++;
		else if (input[i] == 39 && !d_quote)
			s_quote--;
		else if (input[i] == '"' && !s_quote && !d_quote)
			d_quote++;
		else if (input[i] == '"' && !s_quote)
			d_quote--;
		i++;
	}
	if (s_quote || d_quote)
		return (1);
	return (0);
}
