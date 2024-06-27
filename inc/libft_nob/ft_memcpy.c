/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plandolf <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 11:00:54 by plandolf          #+#    #+#             */
/*   Updated: 2023/05/04 12:28:36 by plandolf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	const char	*s;
	char		*d;

	s = src;
	d = dest;
	if (src == NULL && dest == NULL)
		return (dest);
	while (n--)
		*d++ = *s++;
	return (dest);
}

/*int main()
{
	char src[] = "abcdefg";
	ft_memcpy(src + 3, src, 3);
	puts(src);

	int isrc[] = {10, 20, 30, 40, 50};
	int n = sizeof(isrc)/sizeof(isrc[0]);
	int idest[n], i;
	ft_memcpy(idest, isrc, sizeof(isrc));
	printf("\nCopied array is ");
	for (i=0; i<n; i++)
		printf("%d ", idest[i]);
}*/
