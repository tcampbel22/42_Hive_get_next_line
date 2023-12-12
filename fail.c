/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcampbel <tcampbel@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 11:54:58 by tcampbel          #+#    #+#             */
/*   Updated: 2023/12/12 18:58:29 by tcampbel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *ft_append(char *big_buffer, char *new_line)
{
	char *temp;

	temp = ft_strjoin(big_buffer, new_line);
	free (big_buffer);
	return (temp);
}

char *lost_lines(char *big_buffer)
{
	int		i;
	int		j;
	char	*leftover;

	i = 0;
	j = 0;
	while (big_buffer[i] && big_buffer[i] != '\n')
		i++;
//	if (big_buffer)
//		return (free (big_buffer), NULL);
	if (big_buffer[i] == '\n')
		i++;
	leftover = malloc((ft_strlen(big_buffer) - i) + 1);
	if (!leftover)
		return (NULL);
	while (big_buffer[i + j])
	{
		leftover[j] = big_buffer[i + j];
		j++;
	}
	leftover[j] = '\n';
	free (big_buffer);
	return (leftover);
}



char	*extract_line(char *big_buffer)
{
	char *x_line;
	int		i;

	i = 0;
	if (!big_buffer || big_buffer[0])
		return (NULL);
	while (big_buffer[i] && big_buffer[i] != '\n')
		i++;
	if (big_buffer[i] == '\n')
		i++;
	x_line = malloc(BUFFER_SIZE + 1);
	if (!x_line)
		return (NULL);
	i = 0;
	while (big_buffer[i] && big_buffer[i] != '\n')
	{
		x_line[i] = big_buffer[i];
		i++;
	}
	if (big_buffer[i] == '\n')
		x_line[i++] = '\n';
	x_line[i] = '\0';
	return (x_line);
}

char *read_line(char *big_buffer, int fd)
{
	int		bytes_read;
	char	*new_line;

	bytes_read = 1;
	big_buffer = malloc(BUFFER_SIZE + 1);
	if (!big_buffer)
		return (NULL);
	while (!(ft_strchr(big_buffer, '\n'))) 
	{
		bytes_read = read(fd, big_buffer, BUFFER_SIZE);
		if (bytes_read <= 0 && (!(ft_strchr(big_buffer, '\n'))))
		{
			big_buffer[bytes_read] = '\0';
			return (big_buffer);
		}
		else if (bytes_read <= 0)
			return (free (big_buffer), NULL);
//		big_buffer[bytes_read] = '\0';
		new_line = ft_append(big_buffer, new_line);
	}
	free (big_buffer);
//	big_buffer = lost_lines(new_line);
	new_line = extract_line(new_line);
	big_buffer = lost_lines(new_line);
	return (new_line);
}


char *get_next_line (int fd)
{
	static char	*big_buffer;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, NULL, 0) < 0)
		return (NULL);
	line = read_line(big_buffer, fd);
	return (line);
}
