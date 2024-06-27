/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_get_next.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plandolf <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 12:30:22 by plandolf          #+#    #+#             */
/*   Updated: 2023/05/15 12:35:42 by plandolf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin_get_next(char *s1, char *s2)
{
	char	*new_s;
	int		i;
	int		l;

	i = 0;
	l = 0;
	if (!s1)
	{
		s1 = (char *)malloc(1 * sizeof(char));
		s1[0] = '\0';
	}
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	new_s = malloc((ft_strlen(s1) + ft_strlen(s2)) * sizeof(char) + 1);
	if (!new_s)
		return (NULL);
	while (s1[i])
		new_s[l++] = s1[i++];
	i = 0;
	while (s2[i])
		new_s[l++] = s2[i++];
	new_s[l] = '\0';
	free(s1);
	return (new_s);
}
