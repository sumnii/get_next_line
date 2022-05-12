/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumsong <sumsong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 16:58:25 by sumsong           #+#    #+#             */
/*   Updated: 2022/05/12 16:36:41 by sumsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

# define FD_MAX 10240

char	*get_next_line(int fd);
char	*ft_read_buf(int fd, char **save);
char	*ft_cut_line(char **line, char **save);
char	*ft_cut_save(char **save);
void	*ft_close(char **line, char **save);

size_t	ft_strlen(char *str);
void	*ft_calloc(size_t size, size_t count);
int		ft_find_lf(char *str);
char	*ft_strjoin(char **line, char **buf);
char	*ft_idx_dup(char *str, size_t i, size_t j);

#endif