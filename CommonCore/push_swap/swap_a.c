#include "push_swap.h"

void   swap_a(int *sa)
{
    int temp_var;

    temp_var = sa[0];
    sa[0] = sa[1];
    sa[1] = temp_var;
    //escrever a operacao na variavel operations
    write(1, "sa\n", 3);
}