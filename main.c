#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <stdlib.h>
#include "./libft/libft.h"
#include "minishell.h"


/*  Get env PATH to the commands files */

char	*get_path_to_params(char *envp[])
{
	size_t	pos;

	pos = 0;
	while (ft_strncmp("PATH", *envp, 4))
		envp++;
	return (*envp + 5);
}

/*   Test available PATHS with the command name */

char	*get_cmd_path(char *path, char *cmd)
{
	size_t	pos;
	char	**paths;
	char	*pathslash;
	char	*cmd_path;

	paths = ft_split(path, ':');
	pos = 0;
	while (paths[pos])
	{
		pathslash = ft_strjoin(paths[pos], "/");
		cmd_path = ft_strjoin(pathslash, cmd);
		free(pathslash);
		if (!access(cmd_path, 0))
		{
			//free_split(paths);
			return (cmd_path);
		}
		free(cmd_path);
		pos++;
	}
	//free_split(paths);
	return (0);
}

int	error_malloc(void)
{
	printf("Error on malloc\n");
	write(2, "Error on malloc", 15);
	return (1);
}

int	error_pipe(void)
{
	printf("Error on pipe\n");
	write(2, "Error on pipe", 15);
	return (1);
}

/* Get an input, then return the number of pipes outside quotes */

int count_pipes(char *input)
{
	int	quotes;
	int	doble_quotes;
	int	pos;
	int	pipes;

	pos = 0;
	pipes = 0;
	quotes = 0;
	doble_quotes = 0;
	while (input[pos])
	{
		if (input[pos] == 39 && quotes == 0)
			quotes++;
		else if(input[pos] == 39 && quotes == 1)
			quotes--;
		if (input[pos] == 34 && doble_quotes == 0)
			doble_quotes++;
		else if (input[pos] == 34 && doble_quotes == 1)
			doble_quotes--;
		if (input[pos] == '|' && !doble_quotes && !quotes)
			pipes++;
		pos++;
	}
	return(pipes);
}

//Colocar o primeiro pip de entrada como a entrada padrao
//colocar o ultimo pipe como a saida padrao
// fechar os pipes
// pegar a path
// create the split pipes
// call the regular split


void pipes(char *input, char *envp[])
{
	int b;
	int **pipes;
	int	pid;
	t_mini	mini;

	mini.path_to_command = get_path_to_params(envp);
	b = count_pipes(input);
	pipes =  malloc(sizeof(int) * (b));
	if (!pipes)
		error_malloc();
	int i = 0;
	while (i < b)
	{
		pipes[i] =  malloc(sizeof(int) * 2);
		if (!pipes[i])
			error_malloc();
		if (pipe(pipes[i]) == -1)
			 error_malloc();
		i++;
	}
	i = 0;
	while(i < b + 1)
	{
		pid = fork();
		if (pid == 0)
		{
			int j;
			j = 0;
			while (j < b)
			{
				if (i != j)
					close(pipes[j][0]);
				if (i + 1 != j)
					close(pipes[j][1]);
				j++;
			}
		




		}
		i++;
	}




	i = 0;
	while (i < b + 1)
	{
		wait(NULL);
		i++;
	}
	
}

int main(int argc, char *argv[], char *envp[])
{
	char  *prompt;
	char *line;

	(void) argc;
	(void) argv;
 	while (1)
	{
		printf("minishell%%");
		line = readline(prompt);
		if (!line)
			break ;
		printf("%s\n", line);
		pipes(line, envp);
		free(line);
	}
	return (0);
}
