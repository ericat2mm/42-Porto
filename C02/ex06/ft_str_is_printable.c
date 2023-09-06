/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_printable.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emedeiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 15:30:57 by emedeiro          #+#    #+#             */
/*   Updated: 2023/09/04 16:06:28 by emedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

int	ft_str_is_printable(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (!(str[i] >= 32 && str[i] < 127))
			return (0);
		i++;
	}
	return (1);
}

/*int	main(int argc, char **argv)
{

	if( argc == 2)
		printf("%d",ft_str_is_printable(argv[1]));
}*/
