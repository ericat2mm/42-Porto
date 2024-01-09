#include "push_swap.h"

void    rotate_b(t_list *lista)
{
    int index;

    index = 0;
    while (index + 1 < lista->size_b)
    {
        swap(&lista->stack_b[index], &lista->stack_b[index + 1]);
        index++;
    }
    //escrever a operacao na variavel operations
    write(1, "rb\n", 3);
} 