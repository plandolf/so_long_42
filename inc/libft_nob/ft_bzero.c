/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plandolf <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 11:00:35 by plandolf          #+#    #+#             */
/*   Updated: 2023/05/02 11:00:37 by plandolf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_bzero(void *s, size_t n)
{
	size_t	i;
	char	*p;

	i = 0;
	p = s;
	while (i < n)
		p[i++] = 0;
}

/*int main()
 {
	 int i = 0;
	 char p[] = "abcdefg";
	 int arr[] = {1,2,3,4,5};
	 ft_bzero(p, 2);
	 ft_bzero(arr , 2*sizeof(int));
	 while(i < 7)
		 printf("%c", p[i++]);
	 i = 0;
	 while (i < 5)
		 printf("%d, ", arr[i++]);
 }*/
