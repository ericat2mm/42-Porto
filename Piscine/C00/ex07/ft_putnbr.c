/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emedeiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 17:10:28 by emedeiro          #+#    #+#             */
/*   Updated: 2023/08/31 10:54:56 by emedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar( char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int nb)
{
	int	i;

	i = 1000000000;
	if (nb < 0)
	{
		ft_putchar('-');
		nb = -nb;
	}
	while (i >= 1)
	{
		if (nb == 0)
		{
			ft_putchar ('0');
			break ;
		}
		if (nb >= i)
		{
			ft_putchar ('0' + nb / i);
			nb = nb % i;
		}
		i = i / 10;
	}
}

/*int	main(void)
{
	ft_putnbr(340);
}*/
