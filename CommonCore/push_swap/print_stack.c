//imprimir stack
void    print_stack(t_list *lista)
{
    int index;

    index = 0;
    while (index <= lista->size_a)
    {
        ft_putnbr(lista->stack_a[index]);
        ft_putchar('\n');
        index++;
    }
    ft_putchar('\n');
    index = 0;
    while (index <= lista->size_b)
    {
        ft_putnbr(lista->stack_b[index]);
        ft_putchar('\n');
        index++;
    }
    ft_putchar('\n');
}