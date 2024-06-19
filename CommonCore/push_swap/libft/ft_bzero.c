/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emedeiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 16:31:38 by emedeiro          #+#    #+#             */
/*   Updated: 2023/10/09 11:25:47 by emedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t c)
{
	size_t				i;
	unsigned char		*p;

	p = (unsigned char *)s;
	i = -1;
	while (++i < c)
		p[i] = 0;
}
/*
int     main()
{
        char    string[] = "ocao";
        int     length = 4;
        int     i;

        ft_bzero(string, length);
        i = -1;
        while (++i < length)
        {
                if (string[i])
                        printf("%c", string[i]);
                else
                        printf("\\0");
        }
        return (0);
}
*/
