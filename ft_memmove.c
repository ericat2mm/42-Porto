#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char           *d;
	unsigned char           *s;
	size_t                          i;
        
        d = (unsigned char *)dest;
        s = (unsigned char *)src;
        if (d == s)
                return (dest);
        if (d < s)
        {
                i = 0;
                while (i < n)
                {
                        d[i] = s[i];
                        i++;
                }
        }
        else
        {
                i = n;
                while (i-- > 0)
                        d[i] = s[i];
        }
        return (dest);
}
