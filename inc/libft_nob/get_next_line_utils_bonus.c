/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plandolf <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 11:24:12 by plandolf          #+#    #+#             */
/*   Updated: 2023/07/13 10:19:07 by plandolf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*arr;
	size_t	i;
	char	*s;

	i = 0;
	arr = malloc(nmemb * size);
	if (arr == NULL)
		return (NULL);
	s = arr;
	if (size == 0)
		return (arr);
	while (i < (nmemb * size))
		s[i++] = 0;
	return (arr);
}

char	*ft_strjoin_get_next(char *s1, char *s2)
{
	char	*new_s;
	int		i;
	int		l;

	i = 0;
	l = 0;
	if (!s1)
	{
		s1 = malloc(1);
		s1[0] = '\0';
	}
	if (!s1 || !s2)
		return (NULL);
	new_s = malloc(((ft_strlen(s1) + ft_strlen(s2)) + 1) * sizeof(char));
	if (!new_s)
		return (NULL);
	while (s1[i])
		new_s[l++] = s1[i++];
	i = 0;
	while (s2[i])
		new_s[l++] = s2[i++];
	new_s[l] = '\0';
	free(s1);
	return (new_s);
}

char	*ft_strchr_get_next(char *str, int c)
{
	unsigned int	i;
	char			*first;

	first = NULL;
	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] == (char)c)
		{
			first = (char *)&str[i];
			break ;
		}
		i++;
	}
	if ((char)c == str[i])
		return ((char *)&str[i]);
	return (first);
}
