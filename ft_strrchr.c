#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int			len;
	unsigned char		*p;
	unsigned char		find;

	p = (unsigned char *)s;
	find = (unsigned char)c;
	len = 0;
	while (p[len] != '\0')
		len++;
	while (len >= 0)
	{
		if (p[len] == find)
			return ((char *)&p[len]);
		len--;
	}
	return (NULL);
}
/*
int main()
{
    char str[] = "O cao comeu o gato";
    char c = 'a';

    printf("%s\n", ft_strrchr(str,c));
    printf("%s", strrchr(str,c));
}*/
