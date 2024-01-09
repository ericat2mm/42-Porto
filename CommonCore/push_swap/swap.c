#include "push_swap.h"

void    swap(int *argv1, int *argv2)
{
    int temp_var;

    temp_var = *argv1;
    *argv1 = *argv2;
    *argv2 = temp_var;
}