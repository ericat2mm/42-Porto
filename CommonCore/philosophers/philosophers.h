/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emedeiro <emedeiro@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 15:18:45 by emedeiro          #+#    #+#             */
/*   Updated: 2024/09/23 15:18:45 by emedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

#include "libft/libft.h0"
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/time.h>


typedef struct s_philo
{
    int id;
    pthread_t thread;
    int left_fork;
    int right_fork;
    int eat_count;
    struct s_table *table;
    struct timeval last_meal;
}   t_philo;

typedef struct s_table
{
    int philo_count;
    int time_to_die;
    int time_to_eat;
    int time_to_sleep;
    int must_eat_count;
    int someone_died;
    pthread_mutex_t *forks;
    pthread_mutex_t print;
    t_philo *philos;
    struct timeval start;
}   t_table;

int init_table(t_table *table, int argc, char **argv);
void *start_simulation(void *arg);
void *philosopher(void *arg);
void take_forks(t_philo *philo);
void put_forks(t_philo *philo);
void eat(t_philo *philo);
void sleep(t_philo *philo);
void think(t_philo *philo);
void print_status(t_philo *philo, char *status);
#endif