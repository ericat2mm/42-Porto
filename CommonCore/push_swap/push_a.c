#include "push_swap.h"

void    push_a(t_list *lista)
{
    int index;

    //inicializar i com o tamanho da lista A
    index = lista->size_a;
    //Informar que um elemento da lista B vai ser retirado
    lista->stack_b = lista->stack_b - 1;
    //Informar que um elemento vai ser acrescentado a lista A
    lista->stack_a = lista->stack_a + 1;
    //mover cada elemento da pilha uma casa para baixo
    while (index > 0)
    {
        swap(&lista->stack_a[index], &lista->stack_a[index - 1]);
        index--;
    }
    //adicionar o elemento de B em A
    lista->stack_a[0] = lista->stack_b[0];
    //mover cada elemento da pilha uma casa para cima
    index = 0;
    while (index <= lista->size_b)
    {
        lista->stack_b[index] = lista->stack_b[index + 1];
        index++;
    }
    //escrever a operacao na variavel operations
    write(1, "pa\n", 3);
}