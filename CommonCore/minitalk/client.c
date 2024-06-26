/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emedeiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 20:21:43 by emedeiro          #+#    #+#             */
/*   Updated: 2024/06/25 21:09:21 by emedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include "libft/ft_printf.h"

int main(int argc, char **argv)
{
    if (argc != 3)
    {
        ft_printf("ERROR\n./client <PID number> <message>\n");
        return (0);
    }
    int pid = ft_atoi(argv[1]);
    char *str = argv[2];
    int len = ft_strlen(str);
    send_size(pid, len);
    send_message(pid, str, len);
    return (0);
}

void send_size(int pid, int size)
{
    while (size)
    {
        if (size & 1)
            kill(pid, SIGUSR1);
        else
            kill(pid, SIGUSR2);
        size >>= 1;
        usleep(100);
    }
}

void send_message(int pid, char *str, int size)
{
    while (*str)
    {
        while (size)
        {
            if (*str & 1)
                kill(pid, SIGUSR1);
            else
                kill(pid, SIGUSR2);
            *str >>= 1;
            size--;
            usleep(100);
        }
    }
}
