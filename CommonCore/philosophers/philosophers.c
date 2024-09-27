/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emedeiro <emedeiro@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 15:18:20 by emedeiro          #+#    #+#             */
/*   Updated: 2024/09/23 15:18:20 by emedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int main (int argc, char **argv)
{
    t_table table;

    if (argc != 5 && argc != 6)
    {
        printf("Error: Wrong number of arguments\n");
        return (1);
    }
    if (init_table(&table, argc, argv))
    {
        printf("Error: Table initialization failed\n");
        return (1);
    }
    if (start_simulation(&table))
    {
        printf("Error: Simulation failed\n");
        return (1);
    }
    return (0);
}