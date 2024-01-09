#include "push_swap.h"

void    reverse_rotate_a(t_list *lista)
{
    int index;

    index = lista->size_a - 1;
    while (i > 0)
    {
        swap(&lista->stack_a[i], &lista->stack_a[i - 1]);
        i--;
    }
    //escrever a operacao na variavel operations
    write(1, "rra\n", 4);
}