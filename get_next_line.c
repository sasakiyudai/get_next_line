/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syudai <syudai@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 20:55:57 by syudai            #+#    #+#             */
/*   Updated: 2020/11/15 16:06:18 by syudai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		ft_put_line(char **line, char **save, char *buf)
{
	int		flag;
	size_t	n;
	char	*tmp;

	n = ft_strchr(buf, '\n');
	if (!(tmp = ft_strjoin(*line, buf, -1, n)))
		return (-1);
	free(*line);
	*line = tmp;
	tmp = NULL;
	flag = 0;
	if (buf[n] == '\n')
	{
		if (!(tmp = ft_strdup(buf + n + 1)))
			return (-1);
		flag = 1;
	}
	free(*save);
	*save = tmp;
	return (flag);
}

void	free_free(char **save, char **line)
{
	free(*save);
	*save = NULL;
	free(*line);
}

int		get_next_line(int fd, char **line)
{
	int			flag;
	static char	*saves[FD_MAX];
	char		*buf;
	ssize_t		n;

	if (fd < 0 || line == NULL || BUFFER_SIZE < 0 || !(*line = malloc(1)))
		return (-1);
	*line[0] = 0;
	flag = 0;
	if (saves[fd])
		flag = ft_put_line(line, &saves[fd], saves[fd]);
	if (!(buf = malloc(BUFFER_SIZE + 1)))
		flag = -1;
	while (flag == 0 && (n = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[n] = 0;
		flag = ft_put_line(line, &saves[fd], buf);
	}
	free(buf);
	if (flag == -1)
		free_free(&saves[fd], line);
	if (n == -1)
		return (-1);
	return (flag);
}
