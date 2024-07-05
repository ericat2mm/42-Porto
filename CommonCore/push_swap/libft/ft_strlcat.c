/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emedeiro <emedeiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 16:12:19 by emedeiro          #+#    #+#             */
/*   Updated: 2024/06/28 02:37:20 by emedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dst_len;
	size_t	src_len;	
	size_t	space_left;
	size_t	i;

	dst_len = 0;
	while (dst[dst_len] != '\0' && dst_len < size)
		dst_len++;
	src_len = 0;
	while (src[src_len] != '\0')
		src_len++;
	if (dst_len == size)
		return (dst_len + src_len);
	if (size == 0)
		return (dst_len + size);
	space_left = size - dst_len - 1;
	i = 0;
	while (src[i] != '\0' && i < space_left)
	{
		dst[dst_len + i] = src[i];
		i++;
	}
	dst[dst_len + i] = '\0';
	return (dst_len + src_len);
}
