/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaliste <agaliste@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 00:32:33 by agaliste          #+#    #+#             */
/*   Updated: 2021/11/17 22:55:40 by agaliste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	execcmd(char *argv, char **env)
{
	char	**cmd;
	char *path;

	cmd = ft_split(argv, ' ');
	path = find_path(cmd[0], env);
	if (execve(path, cmd, env) == -1)
	{
		ft_freestr(cmd);
		free(path);
		exiterror("Exec Error");
	}
}

static void	child(char **argv, char **env, int *fd)
{
	int		fdin;

	close(fd[0]);
	fdin = open(argv[1], O_RDONLY, 0777);
	if (fdin == -1)
		exiterror("Infile Error");
	dup2(fdin, STDIN_FILENO);
	close(fdin);
	dup2(fd[1], STDOUT_FILENO);
	close(fd[1]);
	execcmd(argv[2], env);
}

static void	daddy(char **argv, char **env, int *fd)
{
	int		fdout;

	close(fd[1]);
	fdout = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fdout == -1)
		exiterror("Outfile Error");
	dup2(fd[0], STDIN_FILENO);
	close(fd[0]);
	dup2(fdout, STDOUT_FILENO);
	close(fdout);
	execcmd(argv[3], env);
}

int	main(int argc, char **argv, char **env)
{
	int	pid;
	int	fd[2];

	check_num_args(argc);
	pipe(fd);
	pid = fork();
	if (pid == -1)
		exiterror("PID Error");
	if (pid == 0)
		child(argv, env, fd);
	else
	{
		pid = fork();
		if (pid == -1)
			exiterror("PID Error");
		if (pid == 0)
			daddy(argv, env, fd);
		else
		{
			close(fd[0]);
			close(fd[1]);
		}
	}
	waitpid(pid, NULL, 0);
	return (0);
}
