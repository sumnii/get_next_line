/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumsong <sumsong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 16:58:08 by sumsong           #+#    #+#             */
/*   Updated: 2022/07/22 16:55:17 by sumsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*save;
	char		*line;

	if (BUFFER_SIZE <= 0 || fd < 0 || fd > FD_MAX)
		return (NULL);
	if (gnl_find_lf(save) != -1)
		return (gnl_cut_save(&save));
	line = gnl_read_buf(fd, &save);
	if (!line)
		return (gnl_close(&line, &save));
	return (gnl_cut_line(&line, &save));
}

char	*gnl_read_buf(int fd, char **save)
{
	char	*line;
	int		read_size;
	char	*buf;

	line = NULL;
	while (gnl_find_lf(line) == -1)
	{
		buf = (char *)gnl_calloc(sizeof(char), BUFFER_SIZE + 1);
		if (!buf)
			return (NULL);
		read_size = read(fd, buf, BUFFER_SIZE);
		if (read_size <= 0 && !line && !(*save))
			return (gnl_close(NULL, &buf));
		line = gnl_strjoin(&line, &buf);
		if (!line)
			return (NULL);
		if (read_size < BUFFER_SIZE)
		{
			free(buf);
			return (gnl_strjoin(save, &line));
		}
	}
	return (line);
}

char	*gnl_cut_line(char **line, char **save)
{
	char	*return_line;
	char	*before_lf;
	int		lf_i;

	lf_i = gnl_find_lf(*line);
	if (lf_i == -1)
	{
		free(*save);
		*save = NULL;
		return (*line);
	}
	before_lf = gnl_idx_dup(*line, 0, lf_i);
	if (!before_lf)
		return (gnl_close(line, save));
	return_line = gnl_strjoin(save, &before_lf);
	*save = gnl_idx_dup(*line, lf_i + 1, gnl_strlen(*line) - 1);
	free(*line);
	return (return_line);
}

char	*gnl_cut_save(char **save)
{
	char	*return_line;
	char	*agnler_lf;
	int		lf_i;

	lf_i = gnl_find_lf(*save);
	return_line = gnl_idx_dup(*save, 0, lf_i);
	if (!return_line)
		return (gnl_close(NULL, save));
	agnler_lf = gnl_idx_dup(*save, lf_i + 1, gnl_strlen(*save) - 1);
	free(*save);
	*save = agnler_lf;
	return (return_line);
}

void	*gnl_close(char **line, char **save)
{
	if (line && *line)
	{
		free(*line);
		*line = NULL;
	}
	if (save && *save)
	{
		free(*save);
		*save = NULL;
	}
	return (NULL);
}
