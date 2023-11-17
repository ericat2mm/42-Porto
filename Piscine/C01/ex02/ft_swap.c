/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emedeiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 13:23:14 by emedeiro          #+#    #+#             */
/*   Updated: 2023/09/01 11:16:12 by emedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_swap(int *a, int *b)
{
	int	auxiliar;

	auxiliar = *a;
	*a = *b;
	*b = auxiliar;
}

/*int	main(void)
{
	int	numero_1;
	int	numero_2;
	int	*ptr_1;
	int	*ptr_2;

	numero_1 = 0;
	numero_2 = 1;
	ptr_1 = &numero_1;
	ptr_2 = &numero_2;
	printf("Numero 1: %d\nNumero 2: %d", numero_1, numero_2);
	ft_swap(ptr_1, ptr_2);
	printf("\nNumero 1: %d\nNumero 2: %d", numero_1, numero_2);
}*/
