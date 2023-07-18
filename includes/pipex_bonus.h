/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcho2 <hcho2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 14:31:07 by hcho2             #+#    #+#             */
/*   Updated: 2023/07/18 14:27:39 by hcho2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

/* write, read, close, access, pipe, dup, dup2, execve, fork */
# include <unistd.h>
# include <sys/types.h>
# include <sys/uio.h>
/* open, unlink */
# include <fcntl.h>
/* malloc, free, exit */
# include <stdlib.h>
/* wait, waitpid*/
# include <sys/wait.h>
/* strerror */
# include <string.h>
/* perror */
# include <stdio.h>
/* errno */
# include <errno.h>
/* get_next_line */
# include "../libft/libft.h"

void	ft_error(char *str, int status);
char	*ft_pathjoin(char *s1, char *s2);
char	**find_path(char **envp);
char	*add_path(char *av, char **path);
void	heredoc(int ac, char **av);
void	usage(void);

#endif
