#include "libft.h"
#include <stdio.h>

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*p;
	size_t			i;

	p = (unsigned char *)b;
	i = 0;
	while (i < len)
	{
		p[i] = (unsigned char)c;
		i++;
	}
	return (b);
}
/*
int main()
{
    char    string[] = "123456";
    int     character;
    int     length;

    character = '#';
    length = 3;
    ft_memset(string + 2, character, length);
    printf("%s", string);
    return (0);
}*/
