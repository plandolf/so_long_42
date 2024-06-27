/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plandolf <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 11:42:59 by plandolf          #+#    #+#             */
/*   Updated: 2023/05/05 17:17:16 by plandolf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>
#include <bsd/string.h>
#include <unistd.h>
#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	char		*d;
	const char	*s;
	size_t		n;
	size_t		r;

	d = dst;
	s = src;
	n = size;
	r = 0;
	if (n != 0)
	{
		while (--n != 0)
		{
			if (*s == '\0')
				break ;
			*d++ = *s++;
		}
		*d = '\0';
	}
	while (src[r] != '\0')
		r++;
	return (r);
}
