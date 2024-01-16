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

int initialization_list(t_list **lista, int argc)
{
    (*lista)->stack_a = 0; //inicializa a pilha a
    (*lista)->stack_b = 0; //inicializa a pilha b
    (*lista)->size_a = argc - 1; //inicializa o tamanho da pilha a
    (*lista)->size_b = 0;   //inicializa o tamanho da pilha b
    (*lista)->operations = NULL; //inicializa a string de operacoes
    return (0);
}

int check_args(int argc, char **argv)
{
    int index;

    index = 0;
    while (index < argc)
    {
        check_numbers(argv[index]); 
        if (check_numbers(argv[index]) == -1)
            return("Error\n");
        index++;
    }
}

int check_numbers(char *str) //verifica se os argumentos sao numeros
{
    int i;
    int j;

    i = 0;
    j = 0;
    if (str[j] == '-' && str[j + 1] >= '0' && str[j + 1] <= '9')
    {
        i++;
        j++;
        while (str[j])
        {
            if (str[j] < '0' || str[j] > '9')
                return(-1);
            j++;
        }
    }
    if (i == ft_strlen(str)) 
        return(0);
}

void print_stack(t_list *lista)
{
    int index;

    index = 0;
    while (index < lista->size_a)
    {
        ft_putnbr_fd(lista->stack_a[index], 1); 
        ft_putchar_fd(' ', 1); 
        index++;
    }
    ft_putchar_fd('\n', 1);
}

void sort_stack(t_list *lista)
{
    int index;

    index = 0;
    while (index < lista->size_a)
    {
        if (lista->stack_a[index] > lista->stack_a[index + 1]) //se o numero da posicao atual for maior que o da proxima posicao
        {
            swap(&lista->stack_a[index], &lista->stack_a[index + 1]); //troca os numeros de posicao
            ft_strjoin(lista->operations, "sa"); 
        }
        index++;
    }
}

void print_operations(t_list *lista)
{
    ft_putstr_fd(lista->operations, 1);
}

int main(int argc, char **argv)
{
    t_list	*lista;

	if (argc == 1)
		return (0);
	lista = malloc(sizeof(t_list)); //aloca memoria para a struct
	if (!lista)
		return (0);
    initialization_list(&lista, argc);
    check_args(argc, argv);
    check_numbers(argv[1]);
    print_stack(lista);
    //chamar a funcao que ordena a pilha 
    sort_stack(lista);
    print_stack(lista);
    //chamar a funcao que imprime as operacoes feitas
    print_operations(lista);
    return (0);
}
