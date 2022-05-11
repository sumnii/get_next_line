/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumsong <sumsong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 16:58:08 by sumsong           #+#    #+#             */
/*   Updated: 2022/05/10 22:19:20 by sumsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*save;
	char		*line;
	
	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	if (ft_find_lf(save) != -1)
		return (ft_cut_save(&save));
	line = ft_read_buf(fd);
	// 리턴 : 버퍼 한 줄
	// 리턴 NULL -> 종료
	if (!line) // read 오류, malloc 오류
		return (ft_close(&line, &save));
	return (ft_cut_line(&line, &save));
	// 리턴 NULL -> malloc 오류 -> 종료(쪼개는 함수 내부에서)
	// 리턴 한줄 -> 개행 뒤 저장하고 개행 앞 잘 저장
}

char	*ft_read_buf(int fd)
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
		if (read_size <= 0 && !line)
			return (NULL);
		// buf[read_size] = '\0';
		line = ft_strjoin(line, buf);
		if (!line)
			return (NULL);
		if (read_size < BUFFER_SIZE) // eof 도달
			return (line);
	}
	return (line);
}

char	*ft_strjoin(char *line, char *buf)
{
	char	*merged;
	size_t	i;
	size_t	j;
	size_t	len;

	if (!buf)
		return (NULL);
	len = ft_strlen(line); // NULL이 들어왔을 때 0이 반환되도록
	len += ft_strlen(buf);
	merged = (char *)ft_calloc(sizeof(char), len + 1);
	if (!merged)
		return (NULL);
	i = 0;
	while (line && line[i])
	{
		merged[i] = line[i];
		++i;
	}
	j = 0;
	while (buf && buf[j])
		merged[i++] = buf[j++];
	if (line)
		free (line);
	if (buf)
		free (buf);
	return (merged);
}

char	*ft_cut_line(char **line, char **save)
{
	char	*return_line;
	char	*before_lf;
	int		lf_i;

	lf_i = ft_find_lf(*line);
	if (lf_i == -1) // eof 도달 + 개행 없음
    {
        free(*save);
        return (*line);
    }
	before_lf = ft_idx_dup(*line, 0, lf_i);
	if (!before_lf)
		return (ft_close(line, save));
	return_line = ft_strjoin(*save, before_lf);
	*save = ft_idx_dup(*line, lf_i + 1, ft_strlen(*line) - 1);
	free(*line);
	return (return_line);
}

char	*ft_idx_dup(char *str, size_t i, size_t j)
{
	size_t	len;
	char	*dup;
	
	len = j - i + 1;
	if (len == 0)
		return (NULL);
	dup = (char *)ft_calloc(sizeof(char), len + 1);
	if (!dup)
		return (NULL);
	while (i <= j)
	{
		dup[i] = str[i];
		++i;
	}
	return (dup);
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

void	*ft_calloc(size_t size, size_t count)
{
	void			*ary;
	unsigned char	*ptr;
	size_t			n;

	n = size * count;
	ary = malloc(n);
	if (!ary)
		return (NULL);
	ptr = ary;
	while (n > 0)
	{
		*ptr = 0;
        ptr++;
		--n;
	}
	return (ary);
}

size_t	ft_strlen(char *str)
{
	size_t	len;

	len = 0;
	while (str && str[len])
		++len;
	return (len);
}

int	ft_find_lf(char *str)
{
	size_t	i;

	i = 0;
	while (str && str[i])
	{
		if (str[i] == '\n')
			return (i);
		++i;
	}
	return (-1);
}