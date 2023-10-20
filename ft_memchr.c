#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*p;
	unsigned char 	find;
	size_t			i;

	p = (unsigned char *)s;
	find = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		if (p[i] == find)
			return (&p[i]);
		i++;
	}
	return (NULL);
}
