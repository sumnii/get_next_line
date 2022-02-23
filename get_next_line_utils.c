/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumsong <sumsong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 16:59:53 by sumsong           #+#    #+#             */
/*   Updated: 2022/02/23 15:38:52 by sumsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	len;

	if (s == NULL)
		return (0);
	len = 0;
	while (s[len])
		++len;
	return (len);
}

char	*ft_strdup(const char *s1)
{
	size_t	len;
	char	*dest;
	size_t	i;

	len = ft_strlen(s1);
	i = 0;
	dest = (char *)malloc(sizeof(char) * (len + 1));
	if (dest == 0)
		return (0);
	while (i < len)
	{
		dest[i] = s1[i];
		++i;
	}
	dest[i] = 0;
	return (dest);
}

char	*ft_strchr(const char *str, int chr)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == (char)chr && str[i + 1])
			return ((char *)&str[i + 1]);
		++i;
	}
	return (NULL);
}

char	*ft_strchr_before(const char *str, int chr)
{
	int		i;
	int		j;
	char	*dup_str;

	i = 0;
	while (str[i])
	{
		if (str[i] == (char)chr)
		{
			dup_str = (char *)malloc(sizeof(char) * (i + 2));
			if (dup_str == NULL)
				return (NULL);
			j = 0;
			while (j <= i)
			{
				dup_str[j] = str[j];
				++j;
			}
			dup_str[j] = '\0';
			return (dup_str);
		}
		++i;
	}
	return (NULL);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		len;
	int		i;

	i = 0;
	len = ft_strlen(s1);
	len += ft_strlen(s2);
	str = (char *)malloc(sizeof(char) * len + 1);
	if (str == NULL)
		return (NULL);
	while (s1 && *s1)
		str[i++] = *s1++;
	while (*s2)
		str[i++] = *s2++;
	str[i] = '\0';
	return (str);
}
