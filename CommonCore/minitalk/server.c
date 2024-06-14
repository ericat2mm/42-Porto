/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emedeiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 22:48:44 by emedeiro          #+#    #+#             */
/*   Updated: 2024/06/05 16:46:18 by emedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

//esta função é chamada quando o servidor recebe um sinal do cliente
//vai ter alocacao de memoria dinamica
//quero funcoes de 25 linhas no maximo

void ft_receive_message(int sig) {
    static char message[1024];
    static int bit = 0;
    static int i = 0;
    static int byte = 0;
    static int msg_index = 0;

    if (sig == SIGUSR1) bit = 0;
    else if (sig == SIGUSR2) bit = 1;

    byte = (byte << 1) | bit;

    if (++i == 8) {
        message[msg_index++] = (char)byte;
        if (byte == '\0' || msg_index >= 1024) {
            ft_putstr_fd(message, 1);
            msg_index = 0;
        }
        i = 0;
        byte = 0;
    }
}

int main(void)
{
    int pid;

    pid = getpid();
    ft_putnbr_fd(pid, 1);
    ft_putstr_fd("\n", 1);
    signal(SIGUSR1, ft_receive_message);
    signal(SIGUSR2, ft_receive_message);
    while (1)
        pause();
    return (0);
}
