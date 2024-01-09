#include "push_swap.h"

void    rotate_ab(t_list *lista)
{
    int index;

    index = 0;
    while (index + 1 < lista->size_a)
    {
        swap(&lista->stack_a[index], &lista->stack_a[index + 1]);
        index++;
    }
    index = 0;
    while (index + 1 < lista->size_b)
    {
        swap(&lista->stack_b[index], &lista->stack_b[index + 1]);
        index++;
    }
    //escrever a operacao na variavel operations
    write(1, "rr\n", 3);
} 