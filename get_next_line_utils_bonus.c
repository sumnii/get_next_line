/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumsong <sumsong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 16:59:53 by sumsong           #+#    #+#             */
/*   Updated: 2022/05/12 14:54:42 by sumsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(char *str)
{
	size_t	len;

	len = 0;
	while (str && str[len])
		++len;
	return (len);
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

char	*ft_strjoin(char **line, char **buf)
{
	char	*merged;
	size_t	i;
	size_t	j;
	size_t	len;

	if (!(*buf))
		return (NULL);
	len = ft_strlen(*line);
	len += ft_strlen(*buf);
	merged = (char *)ft_calloc(sizeof(char), len + 1);
	if (!merged)
		return (NULL);
	i = 0;
	while (*line && (*line)[i])
	{
		merged[i] = (*line)[i];
		++i;
	}
	j = 0;
	while (*buf && (*buf)[j])
		merged[i++] = (*buf)[j++];
	ft_close(line, buf);
	return (merged);
}

char	*ft_idx_dup(char *str, size_t i, size_t j)
{
	size_t	len;
	char	*dup;
	size_t	idx;

	len = j - i + 1;
	if (len == 0)
		return (NULL);
	dup = (char *)ft_calloc(sizeof(char), len + 1);
	if (!dup)
		return (NULL);
	idx = 0;
	while (i <= j)
		dup[idx++] = str[i++];
	return (dup);
}
