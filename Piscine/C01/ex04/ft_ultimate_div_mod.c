/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_div_mod.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emedeiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 11:20:28 by emedeiro          #+#    #+#             */
/*   Updated: 2023/09/01 11:26:58 by emedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_ultimate_div_mod(int *a, int *b)
{
	int	auxiliar;

	auxiliar = *a;
	*a = *a / *b;
	*b = auxiliar % *b;
}

/*int	main(void)
{
	int	i;
	int	j;

	i = 10;
	j = 3;
	ft_ultimate_div_mod(&i, &j);
	printf("Divisao inteira: %d", i);
	printf("\nResto da divisao: %d", j);
}*/
