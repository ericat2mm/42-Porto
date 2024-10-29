/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emedeiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 22:03:10 by emedeiro          #+#    #+#             */
/*   Updated: 2024/10/28 22:52:09 by emedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

int initialize_simulation(t_philo_data *simulation, t_philo *philos, t_mutexes *forks)
{
    simulation->philos = philos;
    simulation->forks = forks;
    // aqui vamos inicializar os mutexes
    if (pthread_mutex_init(&simulation->meal_lock, NULL) != 0)
    {
        pthread_mutex_destroy(&simulation->forks);
        pthread_mutex_destroy(&simulation->philos);
        pthread_mutex_destroy(&simulation->meal_lock);
        return (1);
    }
    return (0);
}
