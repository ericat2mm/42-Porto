#include "libft.h"
#include <stdio.h>
#include <string.h>

size_t	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	dest_len;
	unsigned int	src_len;
	unsigned int	copy_len;
	unsigned int	i;

	dest_len = 0;
	while (dest[dest_len] != '\0' && dest_len < size)
		dest_len++;
	src_len = 0;
	while (src[src_len] != '\0')
		src_len++;
	if (dest_len == size)
		return (dest_len + src_len);
	if (size == 0)
		return (dest_len + size);
	copy_len = size - dest_len - 1;
	i = 0;
	while (src[i] != '\0' && i < copy_len)
	{
		dest[dest_len + i] = src[i];
		i++;
	}
	dest[dest_len + i] = '\0';
	return (dest_len + src_len);
}
/*	
int	main()
{
	char dest[] = "Bem ";
	char src[] = "Vindo";
	printf("%zu\n", ft_strlcat(dest,src, 5));
	printf("%lu\n", strlcat(dest,src, 5));
}*/
