/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emedeiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 10:40:20 by emedeiro          #+#    #+#             */
/*   Updated: 2023/10/09 11:27:43 by emedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_isprint(int c)
{
	if (c >= 32 && c <= 126)
	{
		return (1);
	}
	else
	{
		return (0);
	}
}

/*#include <stdio.h>
int	main(int argc, char **argv)
{
	if (argc == 2)
	{
		printf("%d", ft_isprint(*argv[1]));
	}
	return (0);
}*/
