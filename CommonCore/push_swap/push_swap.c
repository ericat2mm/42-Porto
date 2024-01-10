/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emedeiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 23:09:42 by emedeiro          #+#    #+#             */
/*   Updated: 2024/01/09 23:10:06 by emedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
//quero um main para o meu push swap que receba os numeros como argumentos e armazene em uma pilha
//depois quero que ele verifique se os numeros são repetidos
//depois quero que ele execute o push swap
//depois quero que ele imprima as operacoes feitas
//depois quero que ele imprima o numero de operacoes feitas

int main(int argc, char **argv)
{
    int i;
    int j;
    int *stack_a;
    int *stack_b;
    int size_a;
    int size_b;
    char *operations;
    t_list *lista;

    i = 0;
    j = 0;
    size_a = argc - 1;
    size_b = 0;
    stack_a = malloc(sizeof(int) * size_a);
    stack_b = malloc(sizeof(int) * size_a);
    operations = malloc(sizeof(char) * 1000); //1000 é um numero aleatorio
    lista = malloc(sizeof(t_list));
    lista->stack_a = stack_a; 
    lista->stack_b = stack_b;
    lista->size_a = size_a;
    lista->size_b = size_b;
    lista->operations = operations; 
    if (argc == 1)
        return (0);
    while (i < size_a)
    {
        stack_a[i] = ft_atoi(argv[i + 1]);
        i++;
    }
    i = 0;
    while (i < size_a)
    {
        j = i + 1;
        while (j < size_a)
        {
            if (stack_a[i] == stack_a[j])
            {
                write(1, "Error\n", 6);
                return (0);
            }
            j++;
        }
        i++;
    }
    print_stack(lista);
    push_a(lista);
    print_stack(lista);
}
