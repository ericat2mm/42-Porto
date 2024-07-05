/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emedeiro <emedeiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 16:50:38 by emedeiro          #+#    #+#             */
/*   Updated: 2024/07/02 11:54:42 by emedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include "libft/ft_printf.h"

static int	g_size = 0;

int	main(void)
{
	ft_printf("Server PID: %d\n", getpid());
	while (1)
	{
		if (g_size == 0)
		{
			signal(SIGUSR1, handler_signal);
			signal(SIGUSR2, handler_signal);
		}
		else
		{
			signal(SIGUSR1, handler_message);
			signal(SIGUSR2, handler_message);
		}
	}
	return (0);
}

void	handler_signal(int sig)
{
	static int	size = 0;
	static int	i = 0;

	if (sig == SIGUSR2)
		size = size << 1;
	else
		size = (size << 1) | 1;
	i++;
	if (i == 32)
	{
		g_size = size;
		ft_printf("Received size: %i\n", g_size);
		i = 0;
		size = 0;
	}
}

void	handler_message(int sig)
{
	static char		*str = NULL;
	static int		bitcount = 0;
	static int		j = 0;
	static char		character = 0;

	if (sig == SIGUSR2)
		character <<= 1;
	else
		character = (character << 1) | 1;
	bitcount++;
	if (bitcount == 8)
	{
		if (str == NULL)
			str = ft_create(g_size);
		str[j] = character;
		j++;
		bitcount = 0;
		character = 0;
	}
	if (j == g_size)
	{
		j = 0;
		str = ft_printf_free(str);
	}
}

char	*ft_create(int size)
{
	char	*str;

	str = NULL;
	str = ft_calloc(sizeof(char), (size + 1));
	if (!str)
	{
		free(str);
		return (NULL);
	}
	return (str);
}

char	*ft_printf_free(char *str)
{
	str[g_size] = '\0';
	ft_printf("Received message: %s\n", str);
	free(str);
	g_size = 0;
	return (NULL);
}
