/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emedeiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 23:10:29 by emedeiro          #+#    #+#             */
/*   Updated: 2024/01/09 23:10:32 by emedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//imprimir stack
void    print_stack(t_list *lista)
{
    int index;

    index = 0;
    while (index <= lista->size_a)
    {
        ft_putnbr(lista->stack_a[index]);
        ft_putchar('\n');
        index++;
    }
    ft_putchar('\n');
    index = 0;
    while (index <= lista->size_b)
    {
        ft_putnbr(lista->stack_b[index]);
        ft_putchar('\n');
        index++;
    }
    ft_putchar('\n');
}
