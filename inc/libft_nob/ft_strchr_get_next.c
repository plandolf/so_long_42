/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr_get_next.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plandolf <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 10:13:50 by plandolf          #+#    #+#             */
/*   Updated: 2023/06/06 10:14:45 by plandolf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr_get_next(char *str, int c)
{
	unsigned int	i;
	char			*first;

	first = NULL;
	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] == (char)c)
		{
			first = (char *)&str[i];
			break ;
		}
		i++;
	}
	if ((char)c == str[i])
		return ((char *)&str[i]);
	return (first);
}
