/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emedeiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 14:39:21 by emedeiro          #+#    #+#             */
/*   Updated: 2023/09/06 16:48:01 by emedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*ft_strstr(char *str, char *to_find)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i] != '\0')
	{
		j = 0;
		if (str[i] == to_find[j])
		{
			while (to_find[j] != '\0')
			{
				while (str[i + j] == to_find[j])
					j++;
				if (to_find[j] == '\0')
					return (&str[i]);
				break ;
			}
		}
		i++;
	}
	return (0);
}

/*int	main()
{
	char str[] = "o cao comeu o gato";
	char to_find[] = "comeu";

	printf("%s", ft_strstr(str, to_find));
	return (0);
}*/
