/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thsousa <thsousa@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 13:13:31 by thsousa           #+#    #+#             */
/*   Updated: 2022/12/20 11:21:56 by thsousa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	call_pipex(int argc, char *argv[], char **envp)
{
	int	pid1;
	int	pid2;
	int	fd[2];

	if (argc == 5)
	{
		if (pipe(fd) == -1)
			error(NULL);
		pid1 = child_one(argv, envp, fd);
		pid2 = child_two(argv, envp, fd);
		close(fd[0]);
		close(fd[1]);
		waitpid(pid1, NULL, 0);
		waitpid(pid2, NULL, 0);
	}
	else
	{	
		write(2, "Invalid arguments\n", 18);
		return (0);
	}
	return (0);
}

int	child_one(char *argv[], char **envp, int *fd)
{
	int		file_fd;
	char	**cmd;
	int		pid1;

	file_fd = open(argv[1], O_RDONLY);
	if (file_fd == -1)
		error(argv[1]);
	pid1 = fork();
	if (pid1 < 0)
		error("fork");
	if (pid1 == 0)
	{
		dup2(fd[1], STDOUT_FILENO);
		dup2(file_fd, STDIN_FILENO);
		close(fd[0]);
		close(fd[1]);
		close(file_fd);
		cmd = get_cmd(argv[2]);
		if (execve(get_path(envp, cmd), cmd, envp) == -1)
			error("cmd");
	}
	return (pid1);
}

int	child_two(char *argv[], char **envp, int *fd)
{
	int		file_fd;
	char	**cmd;
	int		pid2;

	file_fd = open(argv[4], O_CREAT | O_WRONLY | O_TRUNC, 0777);
	if (file_fd == -1)
		error(argv[4]);
	cmd = get_cmd(argv[3]);
	pid2 = fork();
	if (pid2 < 0)
		error("fork");
	if (pid2 == 0)
	{
		dup2(fd[0], STDIN_FILENO);
		dup2(file_fd, STDOUT_FILENO);
		close(fd[0]);
		close(fd[1]);
		close(file_fd);
		if (execve(get_path(envp, cmd), cmd, envp) == -1)
			error("cmd");
	}
	return (pid2);
}
