#include "libft.h"

char	*ft_strdup(const char *s1)
{
	int	length;
	int	i;
	char	*s2;

	length = 0;
	while (s1[length] != '\0')
		length++;
	if (s1 == NULL)
                return (NULL);
	s2 = (char *)malloc(length + 1);
	i = 0;
	if (s2 == NULL)
		return (NULL);
	while (i <= length)
	{
		s2[i] = s1[i];
		i++;
	}
	return (s2);
}
