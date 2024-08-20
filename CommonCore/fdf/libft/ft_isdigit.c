/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emedeiro <emedeiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 09:44:34 by emedeiro          #+#    #+#             */
/*   Updated: 2024/08/20 11:04:15 by emedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


int	ft_isdigit(int c)
{
	if (c >= 48 && c <= 57)
	{
		return (1);
	}
	else if (c == '\n')
	{
		return (2);
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
