/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emedeiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 12:30:18 by emedeiro          #+#    #+#             */
/*   Updated: 2023/11/17 12:45:43 by emedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_print_str(char *s)
{
	int	count;

	count = 0;
	while (*s != '\0')
	{
		count += write(1, s, 1);
		s++;
	}
	return (count);
}