/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emedeiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 12:30:18 by emedeiro          #+#    #+#             */
/*   Updated: 2024/02/18 00:20:09 by emedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_print_str(char *s)
{
	int	count;

	count = 0;
	if (s == NULL)
	{
		ft_print_str("(null)");
		return (6);
	}
	else
	{
		while (s[count] != '\0')
		{
			ft_print_char(s[count]);
			count++;
		}
	}
	return (count);
}
