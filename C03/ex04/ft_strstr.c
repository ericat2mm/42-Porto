/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emedeiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 14:39:21 by emedeiro          #+#    #+#             */
/*   Updated: 2023/09/06 14:52:33 by emedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*ft_strstr(char *str, char *to_find)
{
	int	i;

	i = 0;
	while (str[i] != '\0' && to_find[i] != '\0')
	{
		if (str[i] == to_find[i])
			return (&str[i]);
		i++;
	}
	return (&str[i]);
}

int	main(int argc, char **argv)
{
	if (argc == 3)
		printf("%s", ft_strstr(argv[1], argv[2]));
}

