#include "push_swap.h"

void   swap_ab(int *sa, int *sb)
{
    int temp_var_a;
    int temp_var_b;

    temp_var_a = sa[0];
    sa[0] = sa[1];
    sa[1] = temp_var_a;

    temp_var_b = sb[0];
    sb[0] = sb[1];
    sb[1] = temp_var_b;
    //escrever a operacao na variavel operations
    write(1, "ss\n", 3);
}