/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emedeiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 12:57:12 by emedeiro          #+#    #+#             */
/*   Updated: 2023/09/05 14:32:40 by emedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (s1[i] != '\0' || s2[i] != '\0' || i < n)
	{
		if (s1[i] != s2[i])
		{
			return (s1[i] - s2[i]);
			i++;
		}
	}
	return (s1[i] - s2[i]);
}
/*
#include <stdio.h>
int	main (int argc, char **argv)
{
	if (argc == 2)
	{
		printf("%d", ft_strncmp(argv[1], argv[2], 10));
	}
}*/
