/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhill <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 21:12:41 by nhill             #+#    #+#             */
/*   Updated: 2020/11/23 14:58:12 by nhill            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static int	check(int byte, char *re)
{
	if (byte < 0)
		return (-1);
	else if (byte == 0 && !(*re))
		return (0);
	if (byte || ft_strlen(re))
		return (1);
	return (0);
}

static void	proverka(char **point, char **buf, char **line, char *re)
{
	char	*tmp;

	if ((*point = ft_strchr(*buf, '\n')))
	{
		**point = '\0';
		*point += 1;
		ft_strcpy(re, *point);
	}
	tmp = *line;
	*line = ft_strjoin(*line, *buf);
	free(tmp);
}

static char	*check_re(char *re, char **line)
{
	char *point;

	point = NULL;
	*line = ft_strdup("");
	if (re)
	{
		if ((point = ft_strchr(re, '\n')))
		{
			*point = '\0';
			free(*line);
			*line = ft_strdup(re);
			ft_strcpy(re, ++point);
		}
		else
		{
			free(*line);
			*line = ft_strdup(re);
			*re++ = '\0';
		}
	}
	return (point);
}

int			get_next_line(int fd, char **line)
{
	char			*buf;
	int				byte;
	char			*point;
	static char		re[1024][BUFFER_SIZE + 1];

	buf = NULL;
	if (fd < 0 || BUFFER_SIZE < 1
			|| fd > 1024 || read(fd, buf, 0) < 0 || !line)
		return (-1);
	if (!(point = check_re(re[fd], line)))
	{
		if (!(buf = malloc(BUFFER_SIZE + 1)))
			return (-1);
		while (!point && (byte = read(fd, buf, BUFFER_SIZE)))
		{
			buf[byte] = '\0';
			proverka(&point, &buf, line, &re[fd][0]);
		}
		free(buf);
		return (check(byte, re[fd]));
	}
	free(buf);
	return (1);
}
