#include "libft.h"

int	ft_isdigit(int c)
{
	if (c >= 48 && c <= 57)
	{
		return (1);
	}
	else
	{
		return (0);
	}
}

/*int	main (int argc, char **argv)
{
	if (argc == 2)
	{
		char	character;

		character = *argv[1];
		printf("%d", ft_isdigit(character));
	}
	return (0);
}*/
