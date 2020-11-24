/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhill <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 13:11:24 by nhill             #+#    #+#             */
/*   Updated: 2020/11/23 14:57:56 by nhill            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t		ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char		*ft_strchr(const char *str, int ch)
{
	char	*s;
	char	res;

	s = (char *)str;
	res = (char)ch;
	while (*s)
	{
		if (*s == res)
			return (s);
		s++;
	}
	if (res == '\0')
		return (s);
	return (NULL);
}

char		*ft_strdup(const char *str)
{
	char	*ptr;
	int		i;

	ptr = NULL;
	i = 0;
	if (!(ptr = (char *)malloc(sizeof(*ptr) * (ft_strlen(str) + 1))))
		return (NULL);
	while (str[i] != '\0')
	{
		ptr[i] = str[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}

char		*ft_strjoin(char const *s1, char const *s2)
{
	char	*ptr;
	int		i;
	int		j;

	ptr = NULL;
	i = 0;
	j = 0;
	if (!s1 || !s2)
		return (NULL);
	if (!(ptr = (char *)malloc(sizeof(*ptr) * (ft_strlen(s1)) +
					(ft_strlen(s2) + 1))))
		return (NULL);
	while (s1[i] != '\0')
	{
		ptr[j] = s1[i];
		i++;
		j++;
	}
	i = 0;
	while (s2[i] != '\0')
		ptr[j++] = s2[i++];
	ptr[j] = '\0';
	return (ptr);
}

char		*ft_strcpy(char *dest, char *src)
{
	int i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
