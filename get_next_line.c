/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumsong <sumsong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 16:58:08 by sumsong           #+#    #+#             */
/*   Updated: 2022/02/24 14:09:23 by sumsong          ###   ########.fr       */
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

	printf("\n    > [start]\n    > strg : %s\n\n", strg);
	if (strg && ft_strchr_before(strg, '\n') && BUFFER_SIZE != 1)
	{
		res = ft_strdup(ft_strchr_before(strg, '\n'));
		strg = ft_strdup(ft_strchr(strg, '\n'));
		return (res);
	}
	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (buf == NULL)
		return (NULL);
	// buf[BUFFER_SIZE] = '\0';
	while (1)
	{
		read_size = read(fd, buf, BUFFER_SIZE);
		printf("    > [read_size] : %ld\n", read_size);
		if (read_size <= 0)
			return (NULL);
		printf("    > [buf] : %s\n", buf);
		if (ft_strchr_before(buf, '\n'))
		{
			res = ft_strjoin(strg, ft_strchr_before(buf, '\n'));
			// printf("1 // res : %s, strg : %s\n", res, strg);
			strg = ft_strdup(ft_strchr(buf, '\n'));
			// printf("2 // res : %s, strg : %s\n", res, strg);
			free (buf);
			return (res);
		}
		strg = ft_strjoin(strg, buf);
		// printf("3 // strg : %s buf : %s\n", strg, buf);
	}
}
