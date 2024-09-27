/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation_manipulation.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emedeiro <emedeiro@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 16:28:24 by emedeiro          #+#    #+#             */
/*   Updated: 2024/09/23 16:28:24 by emedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void *start_simulation(void *arg)
{
    t_table *table;
    t_philo *philo;
    int i;

    table = (t_table *)arg;
    philo = table->philos;
    i = 0;
    table->start_time = get_time();
    while (i < table->num_philos)
    {
        pthread_create(&philo[i].thread, NULL, &philosopher, &philo[i]);
        i++;
    }
    i = 0;
    while (i < table->num_philos)
    {
        pthread_join(philo[i].thread, NULL);
        i++;
    }
    return (NULL);
}
void *philosopher(void *arg)
{
    t_philo *philo;

    philo = (t_philo *)arg;
    if (philo->id % 2 == 0)
        usleep(100);
    while (1)
    {
        take_forks(philo);
        eat(philo);
        put_forks(philo);
        sleep(philo);
        think(philo);
    }
    return (NULL);
}