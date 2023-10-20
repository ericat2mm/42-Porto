#include "libft.h"

size_t	ft_strlcpy(char *dest, char *src, size_t len)
{
	size_t	i;
	size_t	length_src;

	length_src = 0;
	i = 0;
	while (src[length_src] != '\0')
                length_src++;
	if (len < 1)
		return (length_src);
	while (src[i] != '\0' && i < len - 1)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (length_src);
}
/*
int main()
{
    char dest[] = "Ola ";
    char src[] = "mundo";

    printf("Antes de strlcpy:%s", dest);
    ft_strlcpy(dest, src, 3); 
    printf("\nLength: %zu",ft_strlcpy(dest, src, 3));
     printf("depois de strlcpy:%s", dest);
	return (0);
}*/
