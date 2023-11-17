/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emedeiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 12:23:58 by emedeiro          #+#    #+#             */
/*   Updated: 2023/11/17 12:46:05 by emedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_print_ptr(unsigned long long s, int n, char p, size_t count)
{
	if (s == 0)
		return (ft_print_str("(nil)"));
	count += ft_print_str("0x");
	if (s > (unsigned long long)n - 1)
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
	return (count);
}
