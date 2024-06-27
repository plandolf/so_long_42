/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plandolf <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 09:40:51 by plandolf          #+#    #+#             */
/*   Updated: 2023/07/21 10:50:44 by plandolf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	if (!s || !*s)
		return (0);
	while (s[i] != '\0')
		i++;
	return (i);
}

int	ft_print_char(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_print_str(char *s)
{
	if (!s)
		return (write(1, "(null)", 6));
	write(1, s, ft_strlen(s));
	return (ft_strlen(s));
}

int	ft_number_lenght(long int i)
{
	long int			number_lenght;
	long int			y;

	number_lenght = i;
	y = 0;
	if (number_lenght < 0)
		number_lenght *= -1;
	while (number_lenght > 0)
	{
		number_lenght /= 10;
		y++;
	}
	return (y);
}

int	ft_print_nbr(long int i)
{
	char	*s;
	int		res;

	res = 0;
	s = ft_itoa_printf(i);
	res = ft_print_str(s);
	free(s);
	return (res);
}
