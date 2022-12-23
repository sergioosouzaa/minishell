/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_pipex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thsousa <thsousa@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 13:14:17 by thsousa           #+#    #+#             */
/*   Updated: 2022/12/20 11:21:21 by thsousa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**ft_trim(char **cmd)
{
	int	i;

	i = 0;
	while (cmd[i])
	{
		cmd[i] = ft_strtrim(cmd[i], "'\"");
		i++;
	}
	return (cmd);
}

char	*get_path(char **envp, char **cmd)
{
	char	**path;
	char	*env_path;
	int		i;

	i = -1;
	while (envp[++i])
	{
		if (ft_strnstr(envp[i], "PATH=", 5) != 0)
			env_path = ft_strnstr(envp[i], "PATH=", 5);
	}
	path = ft_split(env_path + 5, ':');
	return (test_access(path, cmd));
}

char	**get_cmd(char *argv)
{
	char	**cmd;

	cmd = ft_split(argv, ' ');
	cmd = ft_trim(cmd);
	return (cmd);
}

char	*test_access(char **path, char **cmd)
{
	char	*temp;
	char	*cmd_path;
	int		i;

	i = -1;
	while (path[++i])
	{	
		if (access(cmd[0], F_OK | X_OK) == 0)
			return (cmd[0]);
		temp = ft_strjoin(path[i], "/");
		cmd_path = ft_strjoin(temp, cmd[0]);
		free(temp);
		if (access(cmd_path, F_OK | X_OK) == 0)
			return (cmd_path);
		free(cmd_path);
	}
	return (0);
}
