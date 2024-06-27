/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plandolf <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 09:40:41 by plandolf          #+#    #+#             */
/*   Updated: 2023/07/04 09:31:14 by plandolf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_print_formats(va_list args, const char format)
{
	int	printed_lenght;

	printed_lenght = 0;
	if (format == 'c')
		printed_lenght += ft_print_char(va_arg(args, int));
	else if (format == 's')
		printed_lenght += ft_print_str(va_arg(args, char *));
	else if (format == 'd' || format == 'i')
		printed_lenght += ft_print_nbr(va_arg(args, int));
	else if (format == 'p')
		printed_lenght += ft_print_ptr((unsigned long int)va_arg(args, void *));
	else if (format == 'u')
		printed_lenght += ft_print_unsigned(va_arg(args, unsigned int));
	else if (format == 'x')
		printed_lenght += ft_print_hex_lower(va_arg(args, unsigned int));
	else if (format == 'X')
		printed_lenght += ft_print_hex_upper(va_arg(args, unsigned int));
	else if (format == '%')
		printed_lenght += ft_print_char('%');
	return (printed_lenght);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	int		printed_lenght;
	va_list	args;

	i = 0;
	printed_lenght = 0;
	va_start(args, str);
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] == '%')
		{
			printed_lenght += ft_print_formats(args, str[i + 1]);
			i++;
		}
		else
			printed_lenght += ft_print_char(str[i]);
		i++;
	}
	va_end(args);
	return (printed_lenght);
}

// int main ()
// {
// 	//char *s = "";
// 	//char c = 0;
// 	//int y = -1;
// 	//int i;
// 	//void *p = 0;
// //	unsigned int x = -11;
// 	//i = ft_printf("%d", y);

// 	//printf("" ,s);
// 	//ft_printf("" ,c);
// 	return 0;
// }
