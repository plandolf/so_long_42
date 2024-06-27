/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plandolf <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 09:45:40 by plandolf          #+#    #+#             */
/*   Updated: 2023/07/04 09:31:14 by plandolf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_hex_lenght(unsigned long int i)
{
	int			y;

	y = 0;
	if (i == 0)
		return (1);
	while (i >= 1)
	{
		i /= 16;
		y++;
	}
	return (y);
}

void	ft_put_ptr(unsigned long int n)
{
	if (n <= 9)
		ft_print_char(n + '0');
	if (n >= 16)
	{
		ft_put_ptr(n / 16);
		ft_put_ptr(n % 16);
	}
	else if (n > 9)
		ft_print_char((n - 10) + 'a');
}

int	ft_print_ptr(unsigned long int n)
{
	int	len;

	len = 0;
	if (n == 0)
		return (ft_print_str("(nil)"));
	len += ft_print_str("0x");
	ft_put_ptr(n);
	len += ft_hex_lenght(n);
	return (len);
}

int	ft_print_unsigned(unsigned int n)
{
	char	*s;
	int		res;

	res = 0;
	s = ft_itoa_printf(n);
	res = ft_print_str(s);
	free(s);
	return (res);
}
