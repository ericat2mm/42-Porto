#include "push_swap.h"

void    swap_b(int *sb)
{
    int temp_var;

    temp_var = sb[0];
    sb[0] = sb[1];
    sb[1] = temp_var;
    //escrever a operacao na variavel operations
    write(1, "sb\n", 3);
}