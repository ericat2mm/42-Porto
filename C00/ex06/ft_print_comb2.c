/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emedeiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 14:21:51 by emedeiro          #+#    #+#             */
/*   Updated: 2023/09/02 14:59:45 by emedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_chars(int p, int u)
{
	char	pri_p;
	char	ult_p;
	char	pri_u;
	char	ult_u;

	pri_p = p / 10 + 48;
	ult_p = p % 10 + 48;
	pri_u = u / 10 + 48;
	ult_u = u % 10 + 48;
	write(1, &pri_p, 1);
	write(1, &ult_p, 1);
	write(1, " ", 1);
	write(1, &pri_u, 1);
	write(1, &ult_u, 1);
	if (p < 98 && u < 100)
	{
		write(1, ", ", 2);
	}
}

void	ft_print_comb2(void)
{
	int	p;
	int	u;

	p = 0;
	while (p < 100)
	{
		u = p +1;
		while (u < 100)
		{
			print_chars(p, u);
			u++;
		}
		p++;
	}
}

int	main(void)
{
	ft_print_comb2();
}
