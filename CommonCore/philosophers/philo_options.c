/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_options.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emedeiro <emedeiro@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 16:38:24 by emedeiro          #+#    #+#             */
/*   Updated: 2024/09/23 16:38:24 by emedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

//eat function
void eat(t_philo *philo)
{
    print_status(philo, "is eating");
    gettimeofday(&philo->last_meal, NULL);
    usleep(philo->table->time_to_eat * 1000); //1000 -> miliseconds
    philo->eat_count++;
}
//sleep function
void sleep(t_philo *philo)
{
    print_status(philo, "is sleeping");
    usleep(philo->table->time_to_sleep * 1000);
}
//think function
void think(t_philo *philo)
{
    print_status(philo, "is thinking");
}