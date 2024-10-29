/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emedeiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 09:44:34 by emedeiro          #+#    #+#             */
/*   Updated: 2023/10/09 11:27:24 by emedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_isdigit(int c)
{
	if (c >= 48 && c <= 57)
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
		char	character;

		character = *argv[1];
		printf("%d", ft_isdigit(character));
	}
	return(0);
}*/
