/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plandolf <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 10:44:45 by plandolf          #+#    #+#             */
/*   Updated: 2023/05/08 12:19:39 by plandolf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "libft.h"

static size_t	ft_digits(int n)
{
	size_t		count;
	long int	nmb;

	count = 0;
	nmb = n;
	if (nmb == 0)
		return (1);
	if (n < 0)
		nmb *= -1;
	while (nmb > 0)
	{
		nmb = nmb / 10;
		count++;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	char		*conv;
	long int	nmb;
	size_t		digits;

	digits = ft_digits(n);
	nmb = n;
	if (n < 0)
	{
		nmb *= -1;
		digits++;
	}
	conv = malloc((digits + 1) * sizeof(char));
	if (conv == NULL)
		return (NULL);
	*(conv + digits) = '\0';
	while (digits--)
	{
		*(conv + digits) = nmb % 10 + '0';
		nmb /= 10;
	}
	if (n < 0)
		*(conv + 0) = '-';
	return (conv);
}
