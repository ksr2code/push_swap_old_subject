/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksmailov <ksmailov@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 10:23:15 by ksmailov          #+#    #+#             */
/*   Updated: 2025/10/15 11:57:41 by ksmailov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_strjoin_free(char *s1, char *s2)
{
	size_t	len_s1;
	size_t	len_s2;
	char	*res;

	if (!s1 && !s2)
		return (NULL);
	if (!s1)
		return (ft_strdup(s2));
	if (!s2)
		return (s1);
	len_s1 = 0;
	while (s1[len_s1])
		len_s1++;
	len_s2 = 0;
	while (s2[len_s2])
		len_s2++;
	res = malloc(sizeof(char) * (len_s1 + len_s2 + 1));
	if (!res)
		return (free(s1), NULL);
	ft_strlcpy(res, s1, len_s1 + 1);
	ft_strlcat(res, (char *)s2, len_s1 + len_s2 + 1);
	free(s1);
	return (res);
}

static char	*ft_linesplit(char *buf, char *strs)
{
	char	*res;
	int		i;
	int		j;

	i = 0;
	while ((buf)[i] && (buf)[i] != '\n')
		i++;
	res = ft_strndup(buf, i + 1);
	if (!res)
		return (free(buf), NULL);
	j = 0;
	while (buf[i + j])
		j++;
	if (buf[i] == '\0')
		strs[0] = '\0';
	else
		ft_strlcpy(&strs[0], buf + i + 1, j + 1);
	free(buf);
	return (res);
}

char	*get_next_line(int fd)
{
	static char	strs[BUFFER_SIZE + 1];
	char		*res;
	int			rd;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	rd = 1;
	res = ft_strjoin_free(NULL, strs);
	while ((!ft_strchr(strs, '\n')) && rd > 0)
	{
		rd = read(fd, strs, BUFFER_SIZE);
		if (rd < 0)
			return (free(res), strs[0] = '\0', NULL);
		strs[rd] = '\0';
		res = ft_strjoin_free(res, strs);
		if (!res)
			return (NULL);
	}
	if (rd == 0 && (!res || res[0] == '\0'))
		return (free(res), strs[0] = '\0', NULL);
	if (ft_strchr(res, '\n'))
		return (ft_linesplit(res, strs));
	return (res);
}
