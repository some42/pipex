/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaliste <agaliste@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 03:14:00 by agaliste          #+#    #+#             */
/*   Updated: 2021/11/22 20:54:18 by agaliste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	exiterror(char *error)
{
	perror(error);
	exit(EXIT_FAILURE);
}

char	*find_path(char *cmd, char **env)
{
	int		i;
	char	*dash_path;
	char	*path;
	char	**envvars;

	i = 0;
	while (ft_strnstr(env[i], "PATH", 4) == 0 && env[i] != NULL)
		i++;
	if (env[i] == NULL)
		exiterror("Path not found");
	envvars = ft_split(env[i] + 5, ':');
	i = 0;
	while (envvars[i])
	{
		dash_path = ft_strjoin(envvars[i], "/");
		path = ft_strjoin(dash_path, cmd);
		free(dash_path);
		if (access(path, F_OK) == 0)
			return (path);
		i++;
	}
	return (0);
}

void	check_num_args(int argc)
{
	if (argc != 5)
	{
		ft_putstr_fd("Arguments Error\n", 2);
		ft_putstr_fd("Usage: ./pipex infile cmd1 cmd2 outfile\n", 2);
		exit(EXIT_FAILURE);
	}
}
