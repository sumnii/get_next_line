/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumsong <sumsong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 16:58:08 by sumsong           #+#    #+#             */
/*   Updated: 2022/04/21 23:02:26 by sumsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_cut_str(char *str, t_list *save, int sign, int fd);
void	ft_move_storage(char **move_from, char **move_to);
char	*ft_save_buf(char *str1, char *str2, char **free_target);
char	*ft_free_storage(t_list *strg, int fd);

char	*get_next_line(int fd)
{
	static t_list	save;
	char			buf[BUFFER_SIZE + 1];
	char			*line;

	while (1)
	{
		if (fd < 0 || fd > OPEN_MAX || BUFFER_SIZE <= 0)
			return (NULL);
		if (ft_lf_idx(save.str[fd], '\n') != -1)
			return (ft_cut_str(save.str[fd], &save, 1, fd));
		if (save.str[fd] && save.size < BUFFER_SIZE)
		{
			line = ft_strdup(save.str[fd]);
			ft_free_storage(&save, fd);
			return (line);
		}
		save.size = read(fd, buf, BUFFER_SIZE);
		if (!save.str[fd] && save.size <= 0)
			return (ft_free_storage(&save, fd));
		buf[save.size] = '\0';
		if (ft_lf_idx(buf, '\n') != -1)
			return (ft_cut_str(buf, &save, 2, fd));
		save.str[fd] = ft_save_buf(save.str[fd], buf, &(save.str[fd]));
	}
}

char	*ft_cut_str(char *str, t_list *save, int sign, int fd)
{
	size_t	i;
	char	*before_lf;
	char	*line;

	i = ft_lf_idx(str, '\n');
	before_lf = ft_stridup(str, 0, i);
	save->after_lf = ft_stridup(str, i + 1, ft_strlen(str) - 1);
	if (sign == 1)
	{
		ft_move_storage(&save->after_lf, &save->str[fd]);
		return (before_lf);
	}
	else
	{
		line = ft_strjoin(save->str[fd], before_lf);
		free(before_lf);
		ft_move_storage(&save->after_lf, &save->str[fd]);
		return (line);
	}
}

void	ft_move_storage(char **move_from, char **move_to)
{
	free(*move_to);
	*move_to = *move_from;
	*move_from = NULL;
}

char	*ft_save_buf(char *save, char *buf, char **free_target)
{
	char	*merge;

	merge = ft_strjoin(save, buf);
	if (*free_target)
	{
		free (*free_target);
		*free_target = NULL;
	}
	return (merge);
}

char	*ft_free_storage(t_list *save, int fd)
{
	if (save->str[fd])
		free(save->str[fd]);
	save->str[fd] = NULL;
	if (save->after_lf)
		free(save->after_lf);
	save->after_lf = NULL;
	save->size = 0;
	return (NULL);
}
