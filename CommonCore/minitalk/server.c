/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emedeiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 16:50:38 by emedeiro          #+#    #+#             */
/*   Updated: 2024/06/25 20:29:49 by emedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include "libft/ft_printf.h"

static int g_size = 0;

int main(void)
{
    ft_printf("Server PID: %d\n", getpid());
    signal(SIGUSR1, handler_signal);
    signal(SIGUSR2, handler_signal);
    while (1)
        pause();
    return (0);
}

void handler_signal(int sig)
{
    static int size = 0;
    static int i = 31;

    if (g_size == 0)
    {
        if (sig == SIGUSR1)
            size |= (1 << i);
        i--;
        if (i < 0)
        {
            g_size = size;
            ft_printf("Received size: %d\n", g_size);
            signal(SIGUSR1, handler_message);
            signal(SIGUSR2, handler_message);
        }
    }
    else
        handler_message(sig);
}

void handler_message(int sig)
{
    static char *str = NULL;
    static int bitcount = 0, j = 0;

    if (!str)
        str = ft_create(g_size);
    if (sig == SIGUSR2)
        str[j] <<= 1;
    else
        str[j] = (str[j] << 1) | 1;
    if (++bitcount == 8)
    {
        bitcount = 0;
        if (++j == g_size)
        {
            str[j] = '\0';
            ft_printf("Received message: %s\n", str);
            free(str);
            str = NULL;
            g_size = 0;
            signal(SIGUSR1, handler_signal);
            signal(SIGUSR2, handler_signal);
        }
    }
}

char *ft_create(int size)
{
    char *str = (char *)malloc(sizeof(char) * (size + 1));
    if (!str)
        return (NULL);
    return (str);
}
char	*ft_printf_free(char *str)
{
	ft_printf("Received message: %s\n", str);
    free(str);
    return (NULL);
}
