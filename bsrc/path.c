/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcho2 <hcho2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 16:54:10 by hcho2             #+#    #+#             */
/*   Updated: 2023/07/14 14:52:14 by hcho2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex_bonus.h"

char	*ft_pathjoin(char *s1, char *s2)
{
	char	*start;
	char	*ret;
	size_t	len1;
	size_t	len2;

	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	ret = malloc(len1 + len2 + 2);
	if (!ret)
		return (NULL);
	start = ret;
	while (*s1)
		*ret++ = *s1++;
	*ret++ = '/';
	while (*s2)
		*ret++ = *s2++;
	*ret = '\0';
	return (start);
}

char	**find_path(char **envp)
{
	char	**path;
	int		i;

	i = 0;
	while (envp[i])
	{
		if (ft_strncmp("PATH=", envp[i], 5) == 0)
			break ;
		i++;
	}
	path = ft_split(&envp[i][5], ':');
	if (!path)
		ft_error("Path error: ");
	return (path);
}

char	*add_path(char *cmd, char **path)
{
	char	**cmd_args;
	char	*cmd_path;
	int		i;

	i = 0;
	cmd_args = ft_split(cmd, ' ');
	while (path[i])
	{
		cmd_path = ft_pathjoin(path[i], cmd_args[0]);
		if (access(cmd_path, F_OK) == 0)
			return (cmd_path);
		free(cmd_path);
		i++;
	}
	ft_error("Command not found");
	return (NULL);
}
