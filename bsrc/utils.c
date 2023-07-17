/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcho2 <hcho2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 15:04:44 by hcho2             #+#    #+#             */
/*   Updated: 2023/07/17 17:13:05 by hcho2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex_bonus.h"

void	ft_putstr_fd(char *str, int fd)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	write(fd, str, len);
}

void	ft_error(char *str)
{
	ft_putstr_fd("pipex: ", 2);
	ft_putstr_fd(str, 2);
	ft_putstr_fd(": ", 2);
	if (errno)
		perror("");
	exit(1);
}

void	usage(void)
{
	ft_putstr_fd("pipex: Too few arguments\n", 2);
	exit(1);
}
