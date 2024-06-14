/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emedeiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 15:52:03 by emedeiro          #+#    #+#             */
/*   Updated: 2023/10/09 11:33:42 by emedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char		*p;
	unsigned char		find;
	size_t				i;

	p = (unsigned char *)s;
	find = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		if (p[i] == find)
			return (&p[i]);
		i++;
	}
	return (NULL);
}
