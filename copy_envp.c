/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_envp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thsousa <thsousa@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 14:40:48 by thsousa           #+#    #+#             */
/*   Updated: 2023/01/23 14:40:49 by thsousa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**copy_env(char **envp)
{
	int		len;
	int		i;
	char	**copy;
	int		j;

	len = 0;
	i = -1;
	j = -1;
	while (envp[len])
		len++;
	copy = malloc(sizeof(char **) * len);
	if (!copy)
		return (NULL);
	copy[len] = NULL;
	while (envp[++j])
	{
		if (!ft_strncmp("OLDPWD", envp[j], 6))
			j++;
		copy[++i] = ft_strdup(envp[j]);
	}
	return (copy);
}

char	**change_envp(char **env, char *new_env)
{
	int		size;
	char	**var_env;
	int		i;

	i = -1;
	size = size_matrix(env) + 1;
	var_env = malloc(sizeof(char **) * size + 1);
	if (!var_env)
		return (NULL);
	var_env[size] = NULL;
	while (++i < size - 1)
	{
		var_env[i] = ft_strdup(env[i]);
		free(env[i]);
	}
	var_env[i] = ft_strdup(new_env);
	free(env);
	free(new_env);
	return (var_env);
}

char	**rmv_envp(char **env, int i)
{
	int		j;
	int		pos;
	char	**var_env;

	j = 0;
	pos = 0;
	var_env = ft_calloc(sizeof(char **), size_matrix(env));
	if (!var_env)
		return (NULL);
	while (env[pos])
	{
		if (pos != i)
		{
			var_env[j] = ft_strdup(env[pos]);
			j++;
		}
		free(env[pos]);
		pos++;
	}
	free(env);
	return (var_env);
}
