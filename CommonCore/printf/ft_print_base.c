/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emedeiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 12:44:49 by emedeiro          #+#    #+#             */
/*   Updated: 2023/11/17 12:50:39 by emedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_base(long int s, int n, char p, size_t count)
{
	if ( s < 0)
	{
		s *= -1;
		ft_print_char('-');
		count++;
	}
	if (s > (long int)n - 1)
	{
		count = ft_print_base(s/n, n, p, count);
		count = ft_print_base(s%n, n, p, count);
	}
	if ((p == 'a' || p == 'A') && s < 16)
	{
		if (s <= 9)
			count += ft_print_char(s + '0');
		else
			count += ft_print_char (s + p - 10);
	}
	if ( s <= 9 && p == 's')
	{
		ft_print_char(s + '0');
		count++;
	}
	return (count);
}
