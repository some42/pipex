#ifndef PIPEX_H
# define PIPEX_H

# include <fcntl.h>
# include <stdlib.h>
# include <string.h>
# include <errno.h>
# include "./libft/libft.h"

/*
** UTILS
*/

void	exiterror(char *error);
char	*find_path(char *cmd, char **env);
void	check_num_args(int argc);

#endif