/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thsousa <thsousa@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 13:13:50 by thsousa           #+#    #+#             */
/*   Updated: 2022/12/20 11:38:02 by thsousa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "./src/libft/libft.h"
# include <sys/wait.h>
# include <stdlib.h>
# include <unistd.h>
# include <errno.h>
# include <fcntl.h>
# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>

char	*get_path(char **envp, char **cmd);
int		child_one(char *argv[], char **envp, int *fd);
int		child_two(char *argv[], char **envp, int *fd);
char	**get_cmd(char *argv);
char	*test_access(char **path, char **cmd);
void	error(char *arg);
void	str_error(char *cmd);
int		call_pipex(int argc, char *argv[], char **envp);
int		validate_line(char *line);

#endif
