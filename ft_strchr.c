#include "libft.h"
#include <string.h>

char	*ft_strchr(const char *s, int c)
{
	unsigned char		find;

	find = (unsigned char)c;
	while (*s != '\0')
	{
		if (*s == find)
			return ((char *)s);
		s++;
	}
	if (find == '\0')
		return ((char *)s);
	return (NULL);
}
