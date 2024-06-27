/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plandolf <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 17:08:30 by plandolf          #+#    #+#             */
/*   Updated: 2023/06/06 10:14:12 by plandolf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
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
