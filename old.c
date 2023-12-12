/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcampbel <tcampbel@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 11:53:23 by tcampbel          #+#    #+#             */
/*   Updated: 2023/12/12 18:55:57 by tcampbel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *ft_append(char *buffer, char *line)
{
	char *temp;

	temp = ft_strjoin(buffer, line);
	free (big_buffer);
	return (temp);
}

char	*find_line(char *buffer)
{
	char *new_line;
	char	*ptr;
	int	i;

	i = 0;
	ptr = buffer;
	while (buffer != '\n')
		i++;
	if (buffer[i] == '\n')
		i++;
	new_line = malloc((strlen(buffer - i) + 1));
	if (!new_line)
		return (NULL);
	new_line = ft_substr(buffer, 0, i);
	buffer  = ft_substr(buffer, i, (ft_strlen(buffer) - i);
	return (new_line);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;
	int			bytes_read;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, NULL, 0) < 0)
		return (NULL);
	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	bytes_read = 1;
	printf("line");
	while (!(ft_strchr(buffer, '\n')))
	{
		printf("line");
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		printf("line");
		if (bytes_read < 0)
			return (free(buffer), NULL);
		buffer[bytes_read] = '\0';
		printf("line");
		line = ft_append(buffer, line);
		printf("%sline", line);
	}
	line = find_line(buffer);
	return (line);
}
