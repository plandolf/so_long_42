/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plandolf <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 09:33:38 by plandolf          #+#    #+#             */
/*   Updated: 2023/05/05 11:01:38 by plandolf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	*ft_memchr(const void *str, int c, size_t n)
{
	size_t				i;
	char				*first;
	const char			*s;

	s = str;
	first = NULL;
	i = 0;
	if (n == 0)
		return (0);
	while (i < n - 1)
	{
		if (s[i] == (char)c)
		{
			first = (char *)&s[i];
			break ;
		}
		i++;
	}
	if ((char)c == s[i])
		return ((char *)&s[i]);
	return (first);
}
