/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emedeiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 11:13:03 by emedeiro          #+#    #+#             */
/*   Updated: 2023/09/07 14:29:47 by emedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int dest_len;
	unsigned int src_len;
	unsigned int copy_len;
	unsigned int i;

	dest_len = 0;
	src_len = 0;
	while (dest[dest_len] != '\0')
		dest_len++;
	while (src[src_len] != '\0')
		src_len++;
	copy_len = size - dest_len - 1;
	i = 0;
	if(size <= dest_len)
		return (size + src_len);	
	while (i < copy_len)
	{
               dest[dest_len + i] = src[i];
	       i++;
	}
        dest[dest_len + copy_len] = '\0';
	return dest_len + src_len;
}

/*#include <stdio.h>
int	main()
{
	char dest[] = "Bem ";
	char src[] = "Vindo";
	printf("%d", ft_strlcat(dest,src, 12));
}*/
