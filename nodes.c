/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nodes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thsousa <thsousa@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 14:38:45 by thsousa           #+#    #+#             */
/*   Updated: 2023/01/23 15:43:45 by thsousa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	complement_fill_node(t_list *node, char **args, int i)
{
	if (args[i][0] == '>' && args[i][1] == '>')
	{
		if (ft_get_outfile2(node, args, i) == 1)
			return (1);
		return (2);
	}
	else if (!(args[i][0] == '|' && !args[i][1]) && args[i][0])
	{
		node->cmd = ft_add_cmd(node->cmd, args[i]);
		return (1);
	}
	else if (args[i][0] == '|' && !args[i + 1])
	{
		node->cmd = ft_add_cmd(node->cmd, args[i]);
		return (1);
	}
	else
		return (-1);
}

int	fill_node(t_list *node, char **args, int i)
{
	int	check;
	int	temp;

	if (args[i][0] == '>' && ft_strlen(args[i]) == 1)
	{
		if (ft_get_outfile(node, args, i) == 1)
			return (1);
		return (2);
	}
	else if (args[i][0] == '<' && ft_strlen(args[i]) == 1)
	{
		if (ft_get_infile(node, args, i) == 1)
			return (1);
		return (2);
	}
	else if (args[i][0] == '<' && args[i][1] == '<')
	{
		temp = (ft_get_infile2(node, args, i));
		return (nbr_temp(temp));
	}
	else
		check = complement_fill_node(node, args, i);
	return (check);
}

void	ft_add_node(t_list **lst)
{
	t_list	*temp;
	t_list	*cur;
	t_list	*prev;

	temp = *lst;
	if (!temp)
		return (ft_lstadd_back(lst, cmd_init()));
	while (temp)
	{
		prev = cur;
		cur = temp;
		temp = temp->next;
	}
	if ((!cur->cmd))
	{
		close_free(cur);
		if (!(*lst)->next)
			*lst = NULL;
		else
		{
			prev->next = NULL;
			cur = NULL;
		}
	}
	ft_lstadd_back(lst, cmd_init());
}

int	verifying_fill_node(t_list *cmds, int check)
{
	if (check == -20)
		return (0);
	if (check < 0)
	{
		free_stack(&cmds);
		return (1);
	}
	return (0);
}

t_list	*create_nodes(char **args, t_env *new_envp)
{
	t_list	*cmds;
	t_list	*current_node;
	int		i;
	int		check;

	i = 0;
	check = 0;
	current_node = NULL;
	cmds = NULL;
	g_status = 0;
	while (check != -20 && args[i] && args[i][0])
	{
		if (check_for_cmd(args, i))
		{
			i += args[i][0] == '|';
			ft_add_node(&cmds);
		}
		current_node = ft_lstlast(cmds);
		current_node->envp = new_envp;
		check = fill_node(current_node, args, i);
		if (verifying_fill_node(cmds, check))
			return (NULL);
		i += check;
	}
	return (return_node(cmds, check, args));
}
