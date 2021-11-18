/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaliste <agaliste@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 14:59:00 by agaliste          #+#    #+#             */
/*   Updated: 2021/11/18 14:59:01 by agaliste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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