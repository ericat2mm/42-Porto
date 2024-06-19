/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emedeiro <emedeiro@student.42porto.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 10:32:01 by emedeiro          #+#    #+#             */
/*   Updated: 2023/10/18 10:39:42 by emedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	i;

	if (!s)
		return (NULL);
	if (start > ft_strlen(s))
	{
		substr = ft_calloc(1, sizeof(char));
		if (!substr)
			return (NULL);
	}
	else
	{
		i = ft_strlen(s + start);
		if (i >= len)
			i = len;
		substr = (char *)malloc(sizeof(char) * (i + 1));
		if (!substr)
			return (NULL);
		substr[i] = '\0';
		while (i--)
			substr[i] = s[start + i];
	}
	return (substr);
}
