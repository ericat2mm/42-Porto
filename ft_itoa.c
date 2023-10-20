#include "libft.h"
#include <stdlib.h>
#include <limits.h>

static int	str_len(int n)
{
    if (n < 10 && n > -10)
        return (1);
    else
        return (1 + str_len(n / 10));
}

static void	convert_to_str(char *str, int n, int len, int sign)
{
    str[len] = '\0';
    while (len--)
    {
        str[len] = (n % 10) + '0';
        n /= 10;
    }
    if (sign == -1)
        str[0] = '-';
}

char	*ft_itoa(int n)
{
    char	*str;
    int		len;
    int		sign;

    if (n == INT_MIN)
        return (ft_strdup("-2147483648"));
    if (n < 0) {
        sign = -1;
        n = -n;
    } else {
        sign = 1;
    }
    len = str_len(n);
    if (sign == -1)
        len++;
    if (!(str = (char *)malloc(sizeof(char) * (len + 1))))
        return (NULL);
    convert_to_str(str, n, len, sign);
    return (str);
}
