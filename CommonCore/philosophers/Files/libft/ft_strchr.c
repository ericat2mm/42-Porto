/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emedeiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 16:11:32 by emedeiro          #+#    #+#             */
/*   Updated: 2023/10/10 09:48:09 by emedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	unsigned char	find;

	find = (unsigned char)c;
	while (*s != '\0')
	{
		if (*s == find)
			return ((char *)s);
		s++;
	}
	if (find == '\0')
		return ((char *)s);
	return (NULL);
}
