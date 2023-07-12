/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcho2 <hcho2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 15:52:00 by hcho2             #+#    #+#             */
/*   Updated: 2023/06/20 11:38:58 by hcho2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

char	*ft_wddup(char const *src, char c)
{
	char	*dst;
	int		len;
	int		i;

	len = 0;
	while (src[len] && src[len] != c)
		len++;
	dst = (char *)malloc(sizeof(char) * len + 1);
	if (!dst)
		return (NULL);
	i = -1;
	while (++i < len)
		dst[i] = src[i];
	dst[i] = '\0';
	return (dst);
}

int	ft_wdcount(char const *str, char c)
{
	int	w_cnt;

	w_cnt = 0;
	while (*str)
	{
		while (*str && *str == c)
			str++;
		if (*str)
			w_cnt++;
		while (*str && *str != c)
			str++;
	}
	return (w_cnt);
}

char	**ft_free_split(char **list)
{
	size_t	i;

	i = 0;
	while (list[i])
	{
		free(list[i]);
		i++;
	}
	free(list);
	return (NULL);
}

char	**ft_split(char const *str, char c)
{
	char	**ret;
	int		i;
	int		size;

	size = ft_wdcount(str, c);
	ret = (char **)malloc(sizeof(char *) * (size + 1));
	if (!ret)
		return (NULL);
	i = 0;
	while (i < size)
	{
		while (*str && *str == c)
			str++;
		if (*str)
		{
			ret[i] = ft_wddup(str, c);
			if (!ret[i++])
				return (ft_free_split(ret));
		}
		while (*str && *str != c)
			str++;
	}
	ret[i] = NULL;
	return (ret);
}
