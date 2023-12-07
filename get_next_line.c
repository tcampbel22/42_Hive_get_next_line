/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcampbel <tcampbel@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 11:54:58 by tcampbel          #+#    #+#             */
/*   Updated: 2023/12/07 16:25:59 by tcampbel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"


char *read_line(static char *str_buf, int fd)
{
	int	bytes_read;
	char	*find_new_line;;

	str_buf = malloc(BUFFER_SIZE + 1)
	if (!str_buf)
	{
		free(str_buf);
		return (NULL);
	}
	find_new_line = strchr(str_buf, '\n');
	if (strchr(str_buf, '\n')
	bytes_read = read(fd, str_buf, BUFFER_SIZE);
	str_buf[bytes_read] = '\0'


		return (str_buf);
}
char *get_next_line (int fd)
{
	char		*new_line;
//	static t_list	*list;
	static char	*str_buf;

//	list = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, &new_line, 0) < 0)
		return (NULL);
	new_line = read_line(str_buf, fd);
	return (new_line);
}
