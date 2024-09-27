/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_status.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emedeiro <emedeiro@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 16:34:43 by emedeiro          #+#    #+#             */
/*   Updated: 2024/09/23 16:34:43 by emedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void print_status(t_philo *philo, char *status)
{
    pthread_mutex_lock(&philo->table->write);
    printf("%ld %d %s\n", get_time_diff(philo->table->start_time), philo->id, status);
    pthread_mutex_unlock(&philo->table->write);
}

//get_time_diff function to calculate the time difference
long get_time_diff(struct timeval start)
{
    struct timeval now;
    long diff;

    gettimeofday(&now, NULL);
    diff = (now.tv_sec - start.tv_sec) * 1000;
    diff += (now.tv_usec - start.tv_usec) / 1000;
    return (diff);
}
