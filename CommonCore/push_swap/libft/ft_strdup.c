/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emedeiro <emedeiro@student.42porto.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 09:50:00 by emedeiro          #+#    #+#             */
/*   Updated: 2023/10/16 11:50:45 by emedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strdup(const char *s1)
{
	int			length;
	int			i;
	char		*s2;

	length = 0;
	while (s1[length] != '\0')
		length++;
	if (s1 == NULL)
		return (NULL);
	s2 = (char *)malloc(length + 1);
	i = 0;
	if (s2 == NULL)
		return (NULL);
	while (i <= length)
	{
		s2[i] = s1[i];
		i++;
	}
	return (s2);
}
