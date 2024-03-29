/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thsousa <thsousa@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 14:42:20 by thsousa           #+#    #+#             */
/*   Updated: 2023/01/23 15:03:20 by thsousa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		g_status;

t_sh	*init(void)
{
	t_sh	*cmd;

	cmd = malloc(sizeof(t_sh));
	cmd->envp = NULL;
	return (cmd);
}

int	validate_prompt(t_sh *cmd)
{
	if (check_quote(cmd->prompt))
	{
		ft_free(&cmd->prompt);
		ft_perror(2, NULL, QUOTES);
		return (0);
	}
	if (check_pipe(cmd))
	{
		ft_free(&cmd->prompt);
		return (0);
	}
	if (check_redir(cmd->prompt))
	{
		ft_free(&cmd->prompt);
		return (0);
	}
	return (1);
}

void	close_prompt(t_env *new_envp, t_sh *cmd)
{
	free_split(new_envp->env);
	free(new_envp);
	free(cmd);
	write(2, "exit\n", 5);
	exit(0);
}

int	main(int argc, char **argv, char **envp)
{
	t_sh	*cmd;
	t_env	*new_envp;

	print_start();
	(void)argv;
	if (argc == 1)
	{
		new_envp = malloc(sizeof(t_env));
		new_envp->env = copy_env(envp);
		cmd = init();
		while (1)
		{
			signals();
			print_prompt(cmd);
			if (!cmd->prompt)
				close_prompt(new_envp, cmd);
			if (validate_prompt(cmd))
				check_input(cmd, new_envp);
		}
		free_split(new_envp->env);
		freetwo_voids(cmd, new_envp);
	}
	return (0);
}
