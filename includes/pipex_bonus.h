/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcho2 <hcho2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 14:31:07 by hcho2             #+#    #+#             */
/*   Updated: 2023/06/20 19:36:33 by hcho2            ###   ########.fr       */
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
# include "get_next_line.h"

void	ft_putstr_fd(char *str, int fd);
int		ft_strcmp(char	*s1, char	*s2);
int		ft_strncmp(char *s1, char *s2, int n);
char	**ft_split(char const *str, char c);
void	ft_error(char *str);
char	*ft_pathjoin(char *s1, char *s2);
char	**find_path(char **envp);
char	*add_path(char *av, char **path);
void	heredoc(int ac, char **av);
void	usage(void);

#endif
