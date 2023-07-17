/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcho2 <hcho2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 11:52:53 by hcho2             #+#    #+#             */
/*   Updated: 2023/07/17 15:40:35 by hcho2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strdup(const char *s)
{
	size_t		i;
	char		*d;

	d = malloc(ft_strlen(s) + 1);
	if (!d)
		return (NULL);
	i = -1;
	while (s[++i])
		d[i] = s[i];
	d[i] = '\0';
	return (d);
}

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	len;

	i = 0;
	len = 0;
	if (size > 0)
	{
		while (i < size - 1 && src[i])
		{
			dest[i] = src[i];
			i++;
		}
		dest[i] = '\0';
	}
	while (src[len])
		len++;
	return (len);
}

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	char	*ret;
	size_t	s_len;

	s_len = ft_strlen(s);
	if (start >= s_len)
	{
		ret = malloc(1);
		if (!ret)
			return (0);
		ret[0] = '\0';
		return (ret);
	}
	if (s_len <= start + len)
		len = s_len - start;
	ret = malloc(len + 1);
	if (!ret)
		return (NULL);
	ft_strlcpy(ret, s + start, len + 1);
	return (ret);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*ret;
	size_t	len1;
	size_t	len2;

	if (!s1 && !s2)
		return (NULL);
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	ret = malloc(len1 + len2 + 1);
	if (!ret)
		return (NULL);
	ft_strlcpy(ret, s1, len1 + 1);
	ft_strlcpy(ret + len1, s2, len2 + 1);
	return (ret);
}
