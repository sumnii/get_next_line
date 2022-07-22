/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumsong <sumsong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 16:58:25 by sumsong           #+#    #+#             */
/*   Updated: 2022/07/22 16:57:25 by sumsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif
# define FD_MAX 10240

char	*get_next_line(int fd);
char	*gnl_read_buf(int fd, char **save);
char	*gnl_cut_line(char **line, char **save);
char	*gnl_cut_save(char **save);
void	*gnl_close(char **line, char **save);

size_t	gnl_strlen(char *str);
void	*gnl_calloc(size_t size, size_t count);
int		gnl_find_lf(char *str);
char	*gnl_strjoin(char **line, char **buf);
char	*gnl_idx_dup(char *str, size_t i, size_t j);

#endif