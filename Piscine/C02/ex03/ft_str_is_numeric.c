/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_numeric.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emedeiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 12:23:33 by emedeiro          #+#    #+#             */
/*   Updated: 2023/09/04 12:35:43 by emedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

int	ft_str_is_numeric(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (!(str[i] >= 0 && str [i] <= 9))
			return (1);
		i++;
	}
	return (0);
}

/*int	main(void)
{
	char	str[] = "ola";

	printf("%d", ft_str_is_numeric(str));
}*/
