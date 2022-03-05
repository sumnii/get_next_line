/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_copy.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumsong <sumsong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 16:58:25 by sumsong           #+#    #+#             */
/*   Updated: 2022/03/05 14:27:47 by sumsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_COPY_H
# define GET_NEXT_LINE_COPY_H

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

char	*get_next_line(int fd);
size_t	ft_strlen(const char *s);
char	*ft_strdup(const char *s1);
char	*ft_strchr_before(const char *str, int chr);
size_t	ft_strchr_idx(const char *str, int chr);
char	*ft_strjoin(char *s1, char *s2, size_t s2_idx);

typedef struct s_strg {
	char	*piece;
	ssize_t	saved_size;
}				t_strg;

#endif