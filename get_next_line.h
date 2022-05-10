/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumsong <sumsong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 16:58:25 by sumsong           #+#    #+#             */
/*   Updated: 2022/05/10 22:14:18 by sumsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 1
#endif

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

char	*get_next_line(int fd);
char	*ft_read_buf(int fd);
char	*ft_strjoin(char **line, char **buf);
char	*ft_cut_line(char **line, char **save);
char	*ft_idx_dup(char *str, size_t i, size_t j);
char	*ft_cut_save(char **save);
void	*ft_close(char **line, char **save);
void	*ft_calloc(size_t size, size_t count);
size_t	ft_strlen(char *str);
int		ft_find_lf(char *str);

#endif