/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thsousa <thsousa@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 11:20:40 by thsousa           #+#    #+#             */
/*   Updated: 2022/12/20 11:47:57 by thsousa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int main(int argc, char *argv[], char *envp[])
{
	char *line;

	(void) envp;
	(void) argc;
	(void) argv;
 	while (1)
	{
		line = readline("minishell % ");
		if (!line)
			break ;
		if (line && *line)
    		add_history (line);
		free(line);
	}
	return (0);
}

