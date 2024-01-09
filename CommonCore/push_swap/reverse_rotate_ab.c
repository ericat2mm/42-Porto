#include "push_swap.h"

void    reverse_rotate_ab(t_list *lista)
{
    int index;

    index = lista->size_a - 1;
    while (i > 0)
    {
        swap(&lista->stack_a[i], &lista->stack_a[i - 1]);
        i--;
    }
    index = lista->size_b - 1;
    while (i > 0)
    {
        swap(&lista->stack_b[i], &lista->stack_b[i - 1]);
        i--;
    }
    //escrever a operacao na variavel operations
    write(1, "rrr\n", 4);
}