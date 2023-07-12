/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcho2 <hcho2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 14:42:49 by hcho2             #+#    #+#             */
/*   Updated: 2023/06/23 15:50:03 by hcho2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex_bonus.h"

void	execute(char *cmd, char **path, char **envp)
{
	char	**cmd_args;
	char	*cmd_path;

	cmd_args = ft_split(cmd, ' ');
	cmd_path = add_path(cmd, path);
	if (execve(cmd_path, cmd_args, envp) == -1)
		ft_error(cmd_args[0]);
}

void	child(char *cmd, char **path, char **envp)
{
	pid_t	pid;
	int		fd[2];

	if (pipe(fd) < 0)
		ft_error("pipe");
	pid = fork();
	if (pid < 0)
		ft_error("fork");
	if (pid == 0)
	{
		close(fd[0]);
		dup2(fd[1], STDOUT_FILENO);
		execute(cmd, path, envp);
	}
	else
	{
		close(fd[1]);
		dup2(fd[0], STDIN_FILENO);
		waitpid(pid, NULL, 0);
	}
}

void	heredoc(int ac, char **av)
{
	char	*eof;
	char	*line;
	int		fd;

	if (ac < 6)
		usage();
	fd = open(".tmp_infile", O_CREAT | O_TRUNC | O_RDWR, 0644);
	if (fd < 0)
		ft_error(".tmp_infile");
	eof = ft_strjoin(av[2], "\n");
	line = get_next_line(0);
	while (line && strcmp(line, eof) != 0)
	{
		ft_putstr_fd(line, fd);
		free(line);
		line = get_next_line(0);
	}
	free(line);
	free(eof);
	close(fd);
	fd = open(".tmp_infile", O_RDONLY);
	if (fd < 0)
		ft_error(".tmp_infile");
	dup2(fd, STDIN_FILENO);
}

void	pipex(int ac, char **av, char **envp, int i)
{
	char	**path;
	int		outfile_fd;

	outfile_fd = open(av[ac - 1], O_CREAT | O_RDWR | O_TRUNC, 0644);
	if (outfile_fd < 0)
		ft_error("file open error");
	path = find_path(envp);
	while (i < ac - 2)
		child(av[i++], path, envp);
	dup2(outfile_fd, STDOUT_FILENO);
	execute(av[ac - 2], path, envp);
}

int	main(int ac, char **av, char **envp)
{
	int		infile_fd;
	int		i;

	if (ac < 5)
		usage();
	if (ft_strcmp(av[1], "here_doc") == 0)
	{
		heredoc(ac, av);
		i = 3;
	}
	else
	{
		i = 2;
		infile_fd = open(av[1], O_RDONLY);
		if (infile_fd < 0)
			ft_error(av[1]);
		dup2(infile_fd, STDIN_FILENO);
	}
	pipex(ac, av, envp, i);
}
