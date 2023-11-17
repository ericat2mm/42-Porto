/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_numbers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emedeiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 11:34:55 by emedeiro          #+#    #+#             */
/*   Updated: 2023/08/25 11:35:05 by emedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	ft_print_numbers(void);

void	ft_print_numbers(void)
{
	int	number;
	int	limit;

	number = '0';
	limit = '9';
	while (number <= limit)
	{
		write(1, &number, 1);
		number++;
	}
}

/*
int 	main()
{
	ft_print_numbers();
}
*/
