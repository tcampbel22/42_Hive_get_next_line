/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcampbel <tcampbel@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 16:47:46 by tcampbel          #+#    #+#             */
/*   Updated: 2023/12/13 18:25:53 by tcampbel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_append(char *storage, char *buffer)
{
	char	*temp;

	temp = ft_strjoin(storage, buffer);
	free(storage);
	storage = NULL;
	return (temp);
}

char	*find_line(char *storage)
{
	char	*new_line;
	int		i;

	i = 0;
	if (!storage[i])
		return (NULL);
	while (storage[i] != '\n' && storage[i])
		i++;
	if (storage[i] == '\n')
		i++;
	new_line = ft_substr(storage, 0, i);
	return (new_line);
}

char	*find_end(char *storage)
{
	int		i;
	char	*ptr;

	i = 0;
	while (storage[i] && storage[i] != '\n')
		i++;
	if (!storage[i])
	{
		free (storage);
		storage = NULL;
		return (NULL);
	}
	if (storage[i] == '\n')
		i++;
	ptr = ft_substr(storage, i, (ft_strlen(storage) - i));
	free (storage);
	storage = NULL;
	return (ptr);
}

char	*read_line(int fd, char *storage)
{
	char	buffer[BUFFER_SIZE + 1];
	int		bytes_read;

	bytes_read = 1;
	while (bytes_read != 0 && (!(ft_strchr(storage, '\n'))))
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read < 0)
			return (NULL);
		buffer[bytes_read] = '\0';
		storage = ft_append(storage, buffer);
	}
	return (storage);
}

char	*get_next_line(int fd)
{
	static char	*storage;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!storage)
		storage = ft_strdup("");
	storage = read_line(fd, storage);
	if (!storage)
	{
		free(storage);
		return (NULL);
	}
	line = find_line(storage);
	storage = find_end(storage);
	return (line);
}
