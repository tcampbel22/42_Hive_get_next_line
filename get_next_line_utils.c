/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcampbel <tcampbel@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 13:49:02 by tcampbel          #+#    #+#             */
/*   Updated: 2023/12/07 15:45:13 by tcampbel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while(str[i])
		i++;
	return (i);
}

void	ft_lstclear(t_list **list)
{
	t_list	*current;
	t_list *temp;

	current = *list;
	if (!list)
		return (NULL);
	while (current)
	{
		*temp = current;
		current = current->next;
		free(temp);
	}
	*list = NULL;
}

t_list	*ft_lstlast(t_list *list)
{
	t_list	*current;

	current = *list;
	if (!list)
		return (NULL);
	while (current)
		current = current->next;
	return (current);
}

void	ft_lstadd_back(t_list **list, t_list *new)
{
	t_list new_node
	if (!list)
		return (NULL);
	if (!*list)
		*lst = new;
		return (NULL);
	new_node = ft_lstlast(list);
	new_node->next = new;
}

char	*ft_strchr(const char *str, int c)
{
	char	a;

	a = c;
	while (*str)
	{
		if (*str == a)
			return ((char *)str);
		str++;
	}
	if (*str == a)
		return ((char *)str);
	return (0);
}
