/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emedeiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 11:46:27 by emedeiro          #+#    #+#             */
/*   Updated: 2023/10/09 11:35:01 by emedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t len)
{
	size_t				i;
	unsigned char		*p;

	i = 0;
	p = (unsigned char *)s;
	while (i < len)
	{
		p[i] = (unsigned char)c;
		i++;
	}
	return (s);
}
/*
int	main()
{
	char	string[0] = "";
	int	character = '#';
	int	length = 4;
	
	ft_memset(string, character, length);
	printf("%s", string);
	memset(string, character, length);
	printf("\n%s", string);
	return (0);
}*/
