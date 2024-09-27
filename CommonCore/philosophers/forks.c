/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emedeiro <emedeiro@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 16:37:29 by emedeiro          #+#    #+#             */
/*   Updated: 2024/09/23 16:37:29 by emedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

//forks function
void take_forks(t_philo *philo)
{
    pthread_mutex_lock(&philo->table->forks[philo->left_fork]);
    print_status(philo, "has taken a fork");
    pthread_mutex_lock(&philo->table->forks[philo->right_fork]);
    print_status(philo, "has taken a fork");
}

void put_forks(t_philo *philo)
{
    pthread_mutex_unlock(&philo->table->forks[philo->left_fork]);
    pthread_mutex_unlock(&philo->table->forks[philo->right_fork]);
}