/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   table_manipulation.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emedeiro <emedeiro@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 16:26:29 by emedeiro          #+#    #+#             */
/*   Updated: 2024/09/23 16:26:29 by emedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int init_table(t_table *table, int argc, char **argv)
{
    int i;

    table->num_philos = ft_atoi(argv[1]);
    table->time_to_die = ft_atoi(argv[2]);
    table->time_to_eat = ft_atoi(argv[3]);
    table->time_to_sleep = ft_atoi(argv[4]);
    table->num_meals = -1;
    if (argc == 6)
        table->num_meals = ft_atoi(argv[5]);
    table->forks = malloc(sizeof(pthread_mutex_t) * table->num_philos);
    if (!table->forks)
        return (1);
    i = 0;
    while (i < table->num_philos)
    {
        pthread_mutex_init(&table->forks[i], NULL);
        i++;
    }
    pthread_mutex_init(&table->write, NULL);
    return (0);
}