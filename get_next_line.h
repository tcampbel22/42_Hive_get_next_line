/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcampbel <tcampbel@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 11:51:36 by tcampbel          #+#    #+#             */
/*   Updated: 2023/12/07 15:39:39 by tcampbel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#ifndef BUFFER_SIZE 42
# define BUFFER_SIZE 42
#endif

#include <unistd.h>
#include <stdlib.h>

typedef struct s_list
{
	char	*buf;
	struct s_list *next;
}	t_list

char	*get_next_line(int fd);
t_list	*ft_lstlast(t_list *list);
void	ft_lstadd_back(t_list **list, t_list *new);
void	*lst_clear(t_list **list);
#endif
