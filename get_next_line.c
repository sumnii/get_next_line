/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumsong <sumsong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 16:58:08 by sumsong           #+#    #+#             */
/*   Updated: 2022/05/12 16:36:18 by sumsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*save;
	char		*line;

	if (BUFFER_SIZE <= 0 || fd < 0 || fd > FD_MAX)
		return (NULL);
	if (ft_find_lf(save) != -1)
		return (ft_cut_save(&save));
	line = ft_read_buf(fd, &save);
	if (!line)
		return (ft_close(&line, &save));
	return (ft_cut_line(&line, &save));
}

char	*ft_read_buf(int fd, char **save)
{
	char	*line;
	int		read_size;
	char	*buf;

	line = NULL;
	while (ft_find_lf(line) == -1)
	{
		buf = (char *)ft_calloc(sizeof(char), BUFFER_SIZE + 1);
		if (!buf)
			return (NULL);
		read_size = read(fd, buf, BUFFER_SIZE);
		if (read_size <= 0 && !line && !(*save))
			return (ft_close(NULL, &buf));
		line = ft_strjoin(&line, &buf);
		if (!line)
			return (NULL);
		if (read_size < BUFFER_SIZE)
		{
			free(buf);
			return (ft_strjoin(save, &line));
		}
	}
	return (line);
}

char	*ft_cut_line(char **line, char **save)
{
	char	*return_line;
	char	*before_lf;
	int		lf_i;

	lf_i = ft_find_lf(*line);
	if (lf_i == -1)
	{
		free(*save);
		*save = NULL;
		return (*line);
	}
	before_lf = ft_idx_dup(*line, 0, lf_i);
	if (!before_lf)
		return (ft_close(line, save));
	return_line = ft_strjoin(save, &before_lf);
	*save = ft_idx_dup(*line, lf_i + 1, ft_strlen(*line) - 1);
	free(*line);
	return (return_line);
}

char	*ft_cut_save(char **save)
{
	char	*return_line;
	char	*after_lf;
	int		lf_i;

	lf_i = ft_find_lf(*save);
	return_line = ft_idx_dup(*save, 0, lf_i);
	if (!return_line)
		return (ft_close(NULL, save));
	after_lf = ft_idx_dup(*save, lf_i + 1, ft_strlen(*save) - 1);
	free(*save);
	*save = after_lf;
	return (return_line);
}

void	*ft_close(char **line, char **save)
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
