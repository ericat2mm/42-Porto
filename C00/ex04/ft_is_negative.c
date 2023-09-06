/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_negative.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emedeiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 12:52:18 by emedeiro          #+#    #+#             */
/*   Updated: 2023/08/30 16:18:56 by emedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_is_negative(int n);

void	ft_is_negative(int n)
{
	char	mensage_a;
	char	mensage_b;

	mensage_a = 'N';
	mensage_b = 'P';
	if (n < 0)
	{
		write(1, &mensage_a, 1);
	}
	else
	{
		write(1, &mensage_b, 1);
	}
}
/*
int	main(void)
{
	ft_is_negative(-5);
}
*/
