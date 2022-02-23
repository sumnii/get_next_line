/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumsong <sumsong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 16:58:08 by sumsong           #+#    #+#             */
/*   Updated: 2022/02/23 15:41:11 by sumsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

char	*get_next_line(int fd)
{
	ssize_t		read_size;
	char		*buf;
	static char	*strg;
	char		*res;

	// printf("start // strg : %s\n", strg);
	if (strg != NULL && ft_strchr(strg, '\n'))
	{
		res = ft_strdup(ft_strchr_before(strg, '\n'));
		return (res);
	}
	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (buf == NULL)
		return (NULL);
	while (1)
	{
		read_size = read(fd, buf, BUFFER_SIZE);
		if (read_size <= 0)
			return (NULL);
		// printf("0 // buf : %s\n", buf);
		if (ft_strchr(buf, '\n'))
		{
			res = ft_strjoin(strg, ft_strchr_before(buf, '\n'));
			// printf("1 // res : %s, strg : %s buf : %s\n", res, strg, buf);
			strg = ft_strdup(ft_strchr(buf, '\n'));
			// printf("2 // res : %s, strg : %s buf : %s\n", res, strg, buf);
			free (buf);
			return (res);
		}
		strg = ft_strjoin(strg, buf);
		// printf("3 // strg : %s buf : %s\n", strg, buf);
	}
}
