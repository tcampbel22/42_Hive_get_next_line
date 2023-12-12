/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcampbel <tcampbel@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 16:47:46 by tcampbel          #+#    #+#             */
/*   Updated: 2023/12/12 18:54:39 by tcampbel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

//This function takes both the static and buffer and joins them together, this is also where the static buffer memory is increased. The temp pointer is declared to the value of the result of strjoin. The functon then returns temp which then changes back to the static 

char *ft_append(char *storage, char *buffer)
{
	char *temp;

	temp = ft_strjoin(storage, buffer);
	free (storage);
	return (temp);
}

//
int	*find_line(char *storage, char *buffer)
{
//	char 	*new_line;
	int	i;

	i = 0;
	while (storage[i] != '\n' && storage[i])
		i++;
	if (storage[i] == '\n')
		i++;
	buffer[i--] = '\0';
	while (i > -1)
	{
		buffer[i] = storage[i];
		i--;
	}
//	new_line = ft_substr(storage, 0, i);
	return (0);
}

char	*find_end(char *storage)
{
	int		i;
	char	*ptr;

	i = 0;
	ptr = ft_calloc(ft_strlen(storage + 1), 1);
	while (storage[i] && storage[i] != '\n')
		i++;
	if (storage[i] == '\n')
		i++;
	ptr = ft_substr(storage, i, (ft_strlen(storage) - i));
//	printf("%zu", ft_strlen(ptr));
	free (storage);
	return (ptr);
}

char	*get_next_line(int fd)
{
	static char	*storage;
	char		buffer[BUFFER_SIZE + 100];
	int			bytes_read;
	char		*result;
//	int			num;
	result = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
//	buffer = ft_calloc(BUFFER_SIZE + 1, 1);
//	if (!buffer)
//		return (NULL);
	if (!storage)
		storage = ft_calloc(1,1);
	else
		storage = find_end(storage);
	bytes_read = 1;
	while (bytes_read != 0 && (!(ft_strchr(storage, '\n'))))
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read <= 0)
		{
			free(storage);
//			if (buffer)
//				return (free(buffer), NULL);
			return (NULL);
		}
		buffer[bytes_read] = '\0';
		storage = ft_append(storage, buffer);
	}
	find_line(storage, buffer);
	printf("%s", storage);
//	num = ft_strlen(result);
//	printf("%d", num);
	result = ft_strdup(buffer);
	return (result);
}
