/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumsong <sumsong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 16:58:25 by sumsong           #+#    #+#             */
/*   Updated: 2022/04/20 02:15:40 by sumsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_list {
	char	*str;
	char	*after_lf;
	ssize_t	size;
}				t_list;

char	*get_next_line(int fd);
char	*ft_cut_str(char *str, t_list *save, int sign);
void	ft_move_storage(char **move_from, char **move_to);
char	*ft_save_buf(char *str1, char *str2, char **free_target);
char	*ft_free_strg(t_list *strg);

size_t	ft_strlen(const char *s);
int		ft_lf_idx(const char *str, int chr);
char	*ft_stridup(const char *s1, int start_i, int end_i);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strdup(const char *s1);

#endif
