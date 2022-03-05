/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumsong <sumsong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 16:58:08 by sumsong           #+#    #+#             */
/*   Updated: 2022/03/03 21:14:42 by sumsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char	*get_next_line(int fd)
{
	static t_strg	strg;
	char			*buf;
	char			*res;

	if (strg.piece && ft_strchr_before(strg.piece, '\n') && BUFFER_SIZE != 1)
	{
		res = ft_strdup(ft_strchr_before(strg.piece, '\n'));
		strg.piece = ft_strdup(ft_strchr(strg.piece, '\n'));
		return (res);
	}
	if (strg.saved_size < BUFFER_SIZE && strg.piece)
	{
		res = ft_strdup(strg.piece);
		strg.piece = 0;
		return (res);
	}
	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (buf == NULL)
		return (NULL);
	while (1)
	{
		strg.saved_size = read(fd, buf, BUFFER_SIZE);
		if (strg.saved_size <= 0)
			return (NULL);
		buf[strg.saved_size] = '\0';
		if (ft_strchr_before(buf, '\n'))
		{
			res = ft_strjoin(strg.piece, ft_strchr_before(buf, '\n'));
			strg.piece = ft_strdup(ft_strchr(buf, '\n'));
			free (buf);
			return (res);
		}
		strg.piece = ft_strjoin(strg.piece, buf);
	}
}
