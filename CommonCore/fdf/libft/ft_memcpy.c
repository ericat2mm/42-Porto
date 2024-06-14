/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emedeiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 11:02:43 by emedeiro          #+#    #+#             */
/*   Updated: 2023/10/09 11:34:18 by emedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char		*a_dest;
	unsigned char		*a_src;
	size_t				i;

	a_dest = (unsigned char *)dest;
	a_src = (unsigned char *)src;
	i = 0;
	if (!dest && !src)
		return (dest);
	while (i < n)
	{
		a_dest[i] = a_src[i];
		i++;
	}
	return (dest);
}
/*
int     main()
{
	char    destination[] = "Ola Mundo";
	char    source[] = "Adeus Mundo";
	int     limit;

	limit = 3;
	ft_memcpy(destination,source,limit);
	printf("%s", destination);
	return (0);
}
*/
