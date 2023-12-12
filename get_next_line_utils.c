/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcampbel <tcampbel@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 13:49:02 by tcampbel          #+#    #+#             */
/*   Updated: 2023/12/12 16:44:41 by tcampbel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*
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
*/

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

char	*ft_strjoin(char const *str1, char const *str2)
{
	size_t	i;
	size_t	j;
	char	*str3;

	i = 0;
	j = 0;
	str3 = (char *)ft_calloc((ft_strlen(str1) + ft_strlen(str2)) + 1, 1);
	if (!str3)
		return (NULL);
	while (str1[i])
	{
		str3[i] = str1[i];
		i++;
	}
	while (str2[j])
	{
		str3[i] = str2[j];
		j++;
		i++;
	}
	str3[i] = '\0';
	return (str3);
}

char	*ft_strdup(const char *src)
{
	int		i;
	char	*dest;

	dest = ft_calloc(ft_strlen(src) + 1, 1);
	if (!dest)
		return (0);
	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = 0;
	return (dest);
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;
	size_t	max;

	max = 0 - 1;
	if (count != 0 && size != 0)
		if (max / count < size)
			return (0);
	ptr = malloc(count * size);
	if (ptr == 0)
		return (0);
	ft_bzero(ptr, count * size);
	return (ptr);
}

void	*ft_bzero(void *s, size_t n)
{
	unsigned char	*str;

	str = s;
	while (n > 0)
	{
		*str = '\0';
		n--;
		str++;
	}
	return (s);
}

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_substr(char const *str, unsigned int start, size_t len)
{
	char	*sub;
	size_t	i;

	i = 0;
	if ((len + start) > ft_strlen(str))
		len = ft_strlen(str) - start;
	if (!str || ft_strlen(str) <= start || len == 0)
		return (ft_strdup(""));
	sub = (char *)ft_calloc((len + 1), 1);
	if (!sub)
		return (NULL);
	while (str[start + i] && len - i > 0)
	{
		sub[i] = str[i + start];
		i++;
	}
	sub[i] = '\0';
	return (sub);
}
