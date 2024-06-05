/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emedeiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 22:56:30 by emedeiro          #+#    #+#             */
/*   Updated: 2024/06/04 22:58:06 by emedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void ft_send_message(int pid, char *message) {
    int i;
    int j;
    int bit;

    i = 0;
    while (message[i]) {
        j = 0;
        while (j < 8) {
            bit = (message[i] >> (7 - j)) & 1;
            if (bit == 0) kill(pid, SIGUSR1);
            else if (bit == 1) kill(pid, SIGUSR2);
            j++;
            usleep(100);
        }
        i++;
    }
    j = 0;
    while (j < 8) {
        bit = (message[i] >> (7 - j)) & 1;
        if (bit == 0) kill(pid, SIGUSR1);
        else if (bit == 1) kill(pid, SIGUSR2);
        j++;
        usleep(100);
    }
}

int main(int argc, char **argv) {
    int pid;

    if (argc != 3) {
        ft_putstr_fd("Usage: ./client [PID] [MESSAGE]\n", 1);
        return (1);
    }
    pid = ft_atoi(argv[1]);
    ft_send_message(pid, argv[2]);
    return (0);
}
