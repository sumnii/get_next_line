/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_copy.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumsong <sumsong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 16:58:08 by sumsong           #+#    #+#             */
/*   Updated: 2022/03/05 14:40:03 by sumsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_copy.h"
#include <stdio.h>

char	*ft_linefeed_in_strg(t_strg *strg);
char	*ft_last_buf(t_strg *strg);
char	*ft_free_strg(t_strg *strg);

char	*get_next_line(int fd)
{
	static t_strg	strg;
	char			buf[BUFFER_SIZE + 1];
	char			*res;

	if (strg.piece && ft_strchr_idx(strg.piece, '\n') && BUFFER_SIZE != 1)
		return (ft_linefeed_in_strg(&strg));
	if (strg.saved_size && strg.saved_size < BUFFER_SIZE && strg.piece)
		return (ft_last_buf(&strg));
	while (1)
	{
		strg.saved_size = read(fd, buf, BUFFER_SIZE);
		if (strg.saved_size <= 0)
			return (NULL);
		buf[strg.saved_size] = '\0';
		if (ft_strchr_idx(buf, '\n'))
		{
			res = ft_strjoin(strg.piece, buf, ft_strchr_idx(buf, '\n'));
			if (buf[ft_strchr_idx(buf, '\n')])
				strg.piece = ft_strdup(&buf[ft_strchr_idx(buf, '\n') + 1]);
			return (res);
		}
		strg.piece = ft_strjoin(strg.piece, buf, BUFFER_SIZE - 1);
	}
}

char	*ft_linefeed_in_strg(t_strg *strg)
{
	char	*res;

	res = ft_strchr_before(strg->piece, '\n');
	strg->piece = &(strg->piece[ft_strchr_idx(strg->piece, '\n') + 1]);
	return (res);
}

char	*ft_last_buf(t_strg *strg)
{
	char	*res;

	res = strg->piece;
	strg->piece = 0;
	return (res);
}

char	*ft_free_strg(t_strg *strg)
{
	free (strg->piece);
	strg->piece = 0;
	strg->saved_size = 0;
	return (NULL);
}
