/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumsong <sumsong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 16:58:08 by sumsong           #+#    #+#             */
/*   Updated: 2022/04/20 02:18:50 by sumsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_cut_str(char *str, t_list *save, int sign);
void	ft_move_storage(char **move_from, char **move_to);
char	*ft_save_buf(char *str1, char *str2, char **free_target);
char	*ft_free_strg(t_list *strg);

char	*get_next_line(int fd)
{
	static t_list	save;
	char			buf[BUFFER_SIZE + 1];
	char			*line;

	while (1)
	{
		if (ft_lf_idx(save.str, '\n') != -1)
			return (ft_cut_str(save.str, &save, 1));
		if (save.str && save.size < BUFFER_SIZE)
		{
			line = ft_strdup(save.str);
			ft_free_strg(&save);
			return (line);
		}
		save.size = read(fd, buf, BUFFER_SIZE);
		if (!save.str && save.size <= 0)
			return (ft_free_strg(&save));
		buf[save.size] = '\0';
		if (ft_lf_idx(buf, '\n') != -1)
			return (ft_cut_str(buf, &save, 2));
		save.str = ft_save_buf(save.str, buf, &(save.str));
	}
}

char	*ft_cut_str(char *str, t_list *save, int sign)
{
	size_t	i;
	char	*before_lf;
	char	*line;

	i = ft_lf_idx(str, '\n');
	before_lf = ft_stridup(str, 0, i);
	save->after_lf = ft_stridup(str, i + 1, ft_strlen(str) - 1);
	if (sign == 1)
	{
		ft_move_storage(&save->after_lf, &save->str);
		return (before_lf);
	}
	else
	{
		line = ft_strjoin(save->str, before_lf);
		free(before_lf);
		ft_move_storage(&save->after_lf, &save->str);
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

char	*ft_free_strg(t_list *save)
{
	if (save->str)
		free(save->str);
	save->str = NULL;
	if (save->after_lf)
		free(save->after_lf);
	save->after_lf = NULL;
	save->size = 0;
	return (NULL);
}
