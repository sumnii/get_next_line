/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumsong <sumsong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 16:58:08 by sumsong           #+#    #+#             */
/*   Updated: 2022/05/10 17:28:56 by sumsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*save;
	char		*line;
	
	if (save에 개행이 있다)
		return (save를 쪼개는 함수(&save));
	line = 버퍼 읽는 함수(fd);
	// 리턴 : 버퍼 한 줄
	// 리턴 NULL -> 종료
	if (!line) // read 오류, malloc 오류
		return (종료 함수);
	return (line 쪼개는 함수(&line, &save));
	// 리턴 NULL -> malloc 오류 -> 종료(쪼개는 함수 내부에서)
	// 리턴 한줄 -> 개행 뒤 저장하고 개행 앞 잘 저장
}

char	*버퍼 읽는 함수(int fd)
{
	char	*line;
	int		read_size;
	char	*buf;

	// line = NULL; 있고 없고 strjoin 안에서의 차이?
	while (line에 개행이 없다)
	{
		buf = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
		read_size = read(fd, buf, BUFFER_SIZE);
		if (read_size < 0)
			return (NULL);
		buf[read_size] = '\0';
		line = ft_strjoin(&line, &buf);
		if (!line)
			return (NULL);
	}
	return (line);
}

char	*ft_strjoin(char **line, char **buf)
{
	char	*merged;
	size_t	i;
	size_t	j;

	if (!(*buf))
		return (NULL);
	line은 비어있을 수 있음
	합치기
	if (merged malloc 오류)
		return (NULL);
	if (*line)
		free (*line);
	if (*buf)
		free (*buf);
	return (merged);
}

char	*line 쪼개는 함수(char **line, char **save)
{
	char	*return_line;

	개행 기준 앞 뒤 복사
	if (malloc 오류)
		return (종료 함수(line, save));
	return_line = line의 개행 앞;
	*save = ft_strjoin(save, line의 개행 뒤);
	free(*line);
	return (return_line);
}

char	*save 쪼개는 함수(char **save)
{
	char	*return_line;

	개행 기준 앞 뒤 복사
	if (malloc 오류)
		return (종료 함수(개행 앞이나 뒤 만들던 것, save));
	return_line = save의 개행 앞;
	*save = ft_strjoin(save, save의 개행 뒤);
	return (return_line)
}

void	*종료 함수(char **line, char **save)
{
	if (*line)
	{
		free(*line);
		*line = NULL;
	}
	if (*save)
	{
		free(*save);
		*save = NULL;
	}
	return (NULL);
}