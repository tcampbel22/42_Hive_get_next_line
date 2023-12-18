/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcampbel <tcampbel@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 11:51:36 by tcampbel          #+#    #+#             */
/*   Updated: 2023/12/18 15:09:16 by tcampbel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <stdlib.h>
# include <unistd.h>

char	*get_next_line(int fd);
size_t	ft_strlen(char *s);
char	*ft_free(char **str);
char	*read_line(int fd, char *storage);
char	*find_end(char *storage);
char	*find_line(char	*storage);
char	*ft_strdup(char *src);
char	*ft_strjoin(char *str1, char *str2);
char	*ft_strchr(char *str, int c);
char	*ft_substr(char *str, size_t start, size_t len);
#endif
