/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plandolf <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 16:20:25 by plandolf          #+#    #+#             */
/*   Updated: 2023/05/02 16:20:27 by plandolf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <bsd/string.h>
#include <string.h>
#include <unistd.h>

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dst_len;
	size_t	src_len;
	size_t	start;
	size_t	dst_end;

	dst_len = ft_strlen((const char *)dst);
	src_len = ft_strlen(src);
	start = 0;
	dst_end = dst_len;
	if (size >= dst_len + 1)
	{
		while (*(src + start) != '\0' && dst_len + start + 1 < size)
		{
			*(dst + dst_end) = *(src + start);
			start++;
			dst_end++;
			if (dst_end == size - 1)
				break ;
		}
	}
	*(dst + dst_end) = '\0';
	if (size <= dst_len)
		return (size + src_len);
	else
		return (dst_len + src_len);
}

/*int main()
{
	char	dest[] = "rrrrrrrrrrrrrr";
	char	dest2[] = "rrrrrrrrrrrrrr";
	strlcat(dest, "lorem ipsum dolor sit amet", 15);
	write(1, "\n", 1);
	write(1, dest, 15);
	ft_strlcat(dest2, "lorem ipsum dolor sit amet", 15);
	write(1, "\n", 1);
	write(1, dest2, 15);
}*/
