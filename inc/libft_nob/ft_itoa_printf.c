/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_printf.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plandolf <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 13:44:07 by plandolf          #+#    #+#             */
/*   Updated: 2023/07/04 09:31:14 by plandolf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_digits(long long int n)
{
	size_t			count;
	long long int	nmb;

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

char	*ft_itoa_printf(long int n)
{
	char			*conv;
	long int		nmb;
	size_t			digits;

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
