/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emedeiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 16:15:31 by emedeiro          #+#    #+#             */
/*   Updated: 2023/10/09 11:37:00 by emedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int				len;
	unsigned char	*p;
	unsigned char	find;

	p = (unsigned char *)s;
	find = (unsigned char)c;
	len = 0;
	while (p[len] != '\0')
		len++;
	while (len >= 0)
	{
		if (p[len] == find)
			return ((char *)&p[len]);
		len--;
	}
	return (NULL);
}
