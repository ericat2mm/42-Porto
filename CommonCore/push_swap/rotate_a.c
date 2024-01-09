#include "push_swap.h"

void    rotate_a(t_list *lista)
{
    int index;

    index = 0;
    while (index + 1 < lista->size_a)
    {
        swap(&lista->stack_a[index], &lista->stack_a[index + 1]);
        index++;
    }
    //escrever a operacao na variavel operations
    write(1, "ra\n", 3);
} 