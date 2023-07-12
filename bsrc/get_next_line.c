/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcho2 <hcho2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 11:31:28 by hcho2             #+#    #+#             */
/*   Updated: 2023/06/20 11:38:10 by hcho2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/get_next_line.h"

void	ft_free_backup(char **backup)
{
	free(*backup);
	*backup = NULL;
}

int	ft_strnl(char *s)
{
	int		i;

	i = 0;
	while (s[i])
	{
		if (s[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

static char	*extract_line(char **backup)
{
	char	*line;
	char	*tmp;
	int		nl_idx;

	line = NULL;
	nl_idx = ft_strnl(*backup);
	if (nl_idx == -1)
	{
		if (ft_strlen(*backup))
			line = ft_strdup(*backup);
		ft_free_backup(backup);
	}
	else
	{
		line = ft_substr(*backup, 0, nl_idx + 1);
		if (!line)
		{
			ft_free_backup(backup);
			return (NULL);
		}
		tmp = *backup;
		*backup = ft_substr(tmp, nl_idx + 1, ft_strlen(tmp));
		free(tmp);
	}
	return (line);
}

static char	*get_line(int fd, char *buf, char **backup)
{
	char	*tmp;
	int		read_size;
	int		nl_idx;

	read_size = read(fd, buf, BUFFER_SIZE);
	if (read_size == -1)
	{
		free(*backup);
		*backup = NULL;
		return (NULL);
	}
	while (read_size > 0)
	{
		buf[read_size] = '\0';
		tmp = *backup;
		*backup = ft_strjoin(tmp, buf);
		free(tmp);
		if (!*backup)
			return (NULL);
		nl_idx = ft_strnl(*backup);
		if (nl_idx != -1)
			return (extract_line(backup));
		read_size = read(fd, buf, BUFFER_SIZE);
	}
	return (extract_line(backup));
}

char	*get_next_line(int fd)
{
	char			buf[BUFFER_SIZE + 1];
	static char		*backup;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (backup != NULL && ft_strnl(backup) != -1)
		return (extract_line(&backup));
	if (backup == NULL)
	{
		backup = ft_strdup("");
		if (!backup)
			return (NULL);
	}
	return (get_line(fd, buf, &backup));
}
