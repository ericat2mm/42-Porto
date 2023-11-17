/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emedeiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 11:55:02 by emedeiro          #+#    #+#             */
/*   Updated: 2023/09/05 15:28:19 by emedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncat(char *dest, char *src)
{
	unsigned int	i;
	unsigned int	len;

	len = 0;
	i = 0;
	while (dest[len] != '\0')
	{
		len++;
	}
	while (src[i] != '\0')
	{
		dest[len + i] = src[i];
		i++;
	}
	dest[len + i] = '\0';
	return (dest);
}

/*#include <stdio.h>
int	main()
{
	char	src[20] = "Dinis";
	char	dest[] = "Dom";

	printf("%s", ft_strncat (dest, src));
}*/
