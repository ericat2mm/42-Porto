#include "libft.h"
#include <stdlib.h>

void    *ft_calloc(size_t count, size_t size)
{
        void    *p;

        p = malloc(count * size);
        if (p == NULL)
                return (p);
	ft_bzero(p, count * size);
        return (p);
}
