/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plandolf <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 08:34:14 by plandolf          #+#    #+#             */
/*   Updated: 2023/05/08 18:19:37 by plandolf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <stdio.h>

static int	ft_count_words(char const *s, char c)
{
	int	count;

	count = 0;
	while (*s != '\0')
	{
		while (*s == c && *s != '\0')
			s++;
		if (*s != c && *s != '\0')
			count++;
		while (*s != c && *s != '\0')
			s++;
	}
	return (count);
}

static int	ft_word_len(char const *s, char c)
{
	int	count;

	count = 0;
	while (*s != '\0')
	{
		while (*s == c && *s != '\0')
			s++;
		while (*s != c && *s != '\0')
		{
			count++;
			s++;
		}
		if (*s == c && *s != '\0')
			break ;
	}
	return (count);
}

static char	*ft_word(char const *s, char c)
{
	char	*word;

	word = malloc(ft_word_len(s, c) * sizeof(char) + 1);
	if (word == NULL)
		return (NULL);
	while (*s != '\0')
	{
		while (*s == c && *s != '\0')
			s++;
		if (*s != c && *s != '\0')
		{
			ft_strlcpy(word, s, ft_word_len(s, c) + 1);
			break ;
		}
	}
	return (word);
}

static void	ft_free_fail(char **arr, int i)
{
	while (i >= 0)
	{
		free(arr[i]);
		i--;
	}
	free(arr);
}

char	**ft_split(char const *s, char c)
{
	char	**arr;
	int		i;
	int		j;

	i = 0;
	j = 0;
	arr = malloc((ft_count_words(s, c) + 1) * sizeof(char *));
	if (arr == NULL)
		return (NULL);
	while (s[j])
	{
		if (s[j] != c && (j == 0 || s[j - 1] == c))
		{
			arr[i] = ft_word(&s[j], c);
			if (arr[i] == NULL)
			{
				ft_free_fail(arr, i);
				return (NULL);
			}
			i++;
		}
		j++;
	}
	arr[i] = NULL;
	return (arr);
}
