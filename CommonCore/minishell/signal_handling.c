/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_handling.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emedeiro <emedeiro@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 15:04:12 by emedeiro          #+#    #+#             */
/*   Updated: 2024/09/23 15:04:12 by emedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void sigint_handler(int sig)
{
    //CTRL+C
    (void)sig;
    ft_putstr_fd("\n", 1);
    printf("minishell$ ");
    //fflush -> força a escrita do buffer
    fflush(stdout); //stdout -> standard output
}

void sigquit_handler(int sig)
{
    //CTRL+\ -> SIGQUIT
    (void)sig;
    ft_putstr_fd("Quit", 1);
    ft_putstr_fd("\n", 1);
    exit(0);
}

void set_signal_handlers(void)
{
    signal(SIGINT, sigint_handler);
    signal(SIGQUIT, sigquit_handler);
}