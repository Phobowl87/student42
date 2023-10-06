/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jenguyen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 09:34:01 by jenguyen          #+#    #+#             */
/*   Updated: 2023/10/06 10:15:14 by jenguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
i
#include "get_next_line.h"

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <string.h>

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s && s[i])
		i++;
	return (i);
}

int	ft_strchr(char *s, char c)
{
	int	i;

	i = -1;
	if (!s)
		return (0);
	while (s && s[++i])
		if (s[i] == c)
			return (1);
	return (0);
}

char	*ft_strndup(char *s, int len)
{
	int		i;
	char	*str;

	if (!s || !len)
		return (NULL);
	str = (char *)malloc((len + 1) * sizeof(char));
	if (!str)
		return (NULL);
	i = -1;
	while (++i < len)
		str[i] = s[i];
	str[i] = 0;
	return (str);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*new;
	int		i;
	int		len;

	len = ft_strlen(s2);
	if (!s1)
		return (ft_strndup(s2, len));
	len += ft_strlen(s1);
	new = malloc(len + 1);
	if (!new)
		return (free(s1), NULL);
	i = 0;
	len = 0;
	while (s1[i])
		new[len++] = s1[i++];
	i = 0;
	while (s2[i])
		new[len++] = s2[i++];
	new[len] = 0;
	free(s1);
	return (new);
}

char	*ft_extract_line(char **buffer)
{
	char	*new;
	char	*temp;
	int		i;

	if (!*buffer)
		return (NULL);
	i = 0;
	temp = *buffer;
	while (temp[i] && temp[i] != '\n')
		i++;
	if (temp[i] == '\n')
		i++;
	new = ft_strndup(temp, i);
	*buffer = ft_strndup(i + temp, ft_strlen(i + temp));
	free(temp);
	return (new);
}

char	*free_buffer(char **buffer)
{
	if (*buffer)
		free(*buffer);
	*buffer = NULL;
	return (0);
}

char	*get_next_line(int fd)
{
	static char	*buffer = NULL;
	char		*str;
	int			bytes_read;

	if (BUFFER_SIZE <= 0 || fd < 0 || read(fd, 0, 0) < 0)
		return (free_buffer(&buffer));
	if (ft_strchr(buffer, '\n'))
		return (ft_extract_line(&buffer));
	str = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!str)
		return (NULL);
	bytes_read = 1;
	while (bytes_read > 0 && !ft_strchr(buffer, '\n'))
	{
		bytes_read = read(fd, str, BUFFER_SIZE);
		str[bytes_read] = '\0';
		buffer = ft_strjoin(buffer, str);
	}
	free_buffer(&str);
	return (ft_extract_line(&buffer));
}

int	main()
{
	int	fd = open ("get_next_line.c", O_RDONLY);
	char	*str;
	int	i;

	i = 1;
	while (i)
	{
		str = get_next_line(fd);
		printf("%s", str);
		free (str);
		if (!str)
			break ;
	}
	close(fd);
	return (0);
}
