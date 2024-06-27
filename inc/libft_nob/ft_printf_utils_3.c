/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_3.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plandolf <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 17:28:16 by plandolf          #+#    #+#             */
/*   Updated: 2023/07/04 09:31:14 by plandolf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_put_hex_lower(unsigned long int n)
{
	if (n <= 9)
		ft_print_char(n + '0');
	else
	{
		if (n >= 16)
		{
			ft_put_hex_lower(n / 16);
			ft_put_hex_lower(n % 16);
		}
		else if (n > 9 && n < 16)
			ft_print_char((n - 10) + 'a');
	}
}

int	ft_print_hex_lower(unsigned long int n)
{
	int	len;

	len = 0;
	if (n == 0)
		return (ft_print_str("0"));
	ft_put_hex_lower(n);
	len += ft_hex_lenght(n);
	return (len);
}

void	ft_put_hex_upper(unsigned long int n)
{
	if (n <= 9)
		ft_print_char(n + '0');
	else
	{
		if (n >= 16)
		{
			ft_put_hex_upper(n / 16);
			ft_put_hex_upper(n % 16);
		}
		else if (n > 9 && n < 16)
			ft_print_char((n - 10) + 'A');
	}
}

int	ft_print_hex_upper(unsigned long int n)
{
	int	len;

	len = 0;
	if (n == 0)
		return (ft_print_str("0"));
	ft_put_hex_upper(n);
	len += ft_hex_lenght(n);
	return (len);
}
