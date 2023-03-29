/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_print_env.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thsousa <thsousa@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 15:06:08 by thsousa           #+#    #+#             */
/*   Updated: 2023/01/23 15:08:34 by thsousa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	exec_exports(char *cmd, t_env *envp)
{
	char	*var;
	char	*value;
	char	*new_var;
	char	*tmp;

	if (!cmd)
		return (0);
	var = get_var(cmd);
	value = get_value(cmd);
	if (!var)
		return (0);
	if (!value)
		value = ft_strdup("");
	exec_unset(var, envp);
	var = ft_new_trim(var);
	tmp = value;
	value = ft_strjoin("=", value);
	free (tmp);
	new_var = ft_strjoin(var, "");
	tmp = new_var;
	new_var = ft_strjoin(new_var, value);
	free(tmp);
	envp->env = change_envp(envp->env, new_var);
	freetwo_ptrs(&var, &value);
	return (0);
}

char	*ft_get_env(char **envp, char *var)
{
	int	i;

	i = 0;
	while (envp[i])
	{
		if (!ft_strncmp(envp[i], var, ft_strlen(var))
			&& envp[i][ft_strlen(var)] == '=')
			break ;
		i++;
	}
	if (envp[i])
		return (ft_substr(envp[i], ft_strlen(var) + 1, ft_strlen(envp[i])
				- ft_strlen(var) - 1));
	return (NULL);
}

char	*get_var(char *cmd)
{
	int		i;
	char	*var;
	int		j;

	i = 0;
	j = -1;
	while (cmd[i] && cmd[i] != '=')
		i++;
	if (i == 0 || !cmd[i])
		return (NULL);
	var = malloc(sizeof(char *) * i + 1);
	if (!var)
		return (NULL);
	if (ft_ismetachar(cmd[j]) || ft_isdigit(cmd[j]))
	{
		ft_free(&var);
		return (NULL);
	}
	while (++j < i && cmd[j])
		var[j] = cmd[j];
	var[j] = '\0';
	var = ft_new_trim(var);
	return (var);
}

char	*get_value(char *cmd)
{
	int		i;
	char	*value;

	i = 0;
	value = NULL;
	while (cmd[i])
	{
		if (cmd[i] == '=' && cmd[i + 1])
		{
			if (cmd[i + 1] == '\'' || cmd[i + 1] == '"')
				i++;
			value = ft_strdup(&cmd[i + 1]);
			return (value);
		}
		i++;
	}
	return (value);
}

void	exec_unset(char *cmd, t_env *envp)
{
	int		i;
	int		pos;
	char	*aux_env;

	i = 0;
	pos = -1;
	while (envp->env[i])
	{
		aux_env = get_var(envp->env[i]);
		if (!ft_strncmp(cmd, envp->env[i], ft_strlen(cmd)) && \
			ft_strlen(aux_env) == ft_strlen(cmd))
			pos = i;
		ft_free(&aux_env);
		i++;
	}
	if (pos >= 0)
		envp->env = rmv_envp(envp->env, pos);
}
