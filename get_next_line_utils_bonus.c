/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcampbel <tcampbel@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 13:49:02 by tcampbel          #+#    #+#             */
/*   Updated: 2023/12/18 15:10:11 by tcampbel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_strchr(char *str, int c)
{
	char	a;

	a = c;
	if (!str)
		return (NULL);
	while (*str)
	{
		if (*str == a)
			return ((char *)str);
		str++;
	}
	if (*str == a)
		return ((char *)str);
	return (NULL);
}

char	*ft_strjoin(char *str1, char *str2)
{
	size_t	i;
	size_t	j;
	char	*str3;

	i = 0;
	j = 0;
	str3 = (char *)malloc((ft_strlen(str1) + ft_strlen(str2)) + 1);
	if (!str3)
		return (ft_free(&str1));
	while (str1[i])
	{
		str3[i] = str1[i];
		i++;
	}
	while (str2[j])
	{
		str3[i + j] = str2[j];
		j++;
	}
	str3[i + j] = '\0';
	free(str1);
	str1 = NULL;
	return (str3);
}

char	*ft_strdup(char *src)
{
	int		i;
	char	*dest;

	dest = malloc(ft_strlen(src) + 1);
	if (!dest)
		return (NULL);
	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = 0;
	return (dest);
}

size_t	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_substr(char *str, size_t start, size_t len)
{
	char	*sub;
	size_t	i;

	i = 0;
	if (!str || ft_strlen(str) <= start || len == 0)
		return (ft_strdup(""));
	if ((len + start) > ft_strlen(str))
		len = ft_strlen(str) - start;
	sub = (char *)malloc((len + 1));
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
