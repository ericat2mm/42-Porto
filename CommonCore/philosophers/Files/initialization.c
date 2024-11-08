/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emedeiro <emedeiro@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 22:03:10 by emedeiro          #+#    #+#             */
/*   Updated: 2024/11/08 12:58:48 by emedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

int initialize_simulation(t_philo_data *simulation, t_philo *philos, t_mutexes *forks)
{
    int i;
    int j;
    
    simulation->philos = philos;
    simulation->forks = forks;
    if (pthread_mutex_init(&simulation->meal_lock, NULL) != 0)
    {
        ft_printf("Failed to initialize meal lock mutex\n");
        return (1);
    }
    i = -1;
    j = -1;
    while (++i < simulation->philos)
    {
        if (pthread_mutex_init(&forks[i].mutex, NULL) != 0)
        {
            ft_printf("Failed to initialize fork mutex for philosopher %d\n", i);
            while (++j < i)
                pthread_mutex_destroy(&forks[j].mutex);
            pthread_mutex_destroy(&simulation->meal_lock);
            return 1;
        }
    }
    return (0);
}

int initialization_forks(t_philo_data *sim, t_mutexes *forks, int num_forks)
{
    int i;

    i = -1;
    while (++i < num_forks)
    {
        if (pthread_mutex_init(&forks[i], NULL) != 0)
			destroy_all(sim, "[Mutex Init ERROR]\n", i, 1);
    }
}

void initialization_philos(t_philo_data *sim, t_philo *philo, int philo_count)
{
    int i;

    i = -1;
    while (++i < philo_count)
    {
        sim->philos[i].id_philo = i + 1;
        sim->philos[i].times.die = sim->die_time;
        sim->philos[i].times.eat = sim->eat_time;
        sim->philos[i].times.sleep = sim->sleep_time;
        sim->philos[i].times.last_meal = current_time();
        sim->philos[i].need_to_eat = sim->need_to_eat;
        sim->philos[i].meals_eaten = 0;
        sim->philos[i].philo_count = philo_count;
        sim->philos[i].mutexes.left_fork = &sim->forks[i];
        if (i == 0)
            sim->philos[i].mutexes.right_fork = &sim->forks[philo_count - 1];
        else
            sim->philos[i].mutexes.right_fork = &sim->forks[i - 1];
        sim->philos[i].mutexes.meal_lock = &sim->meal_lock;
    }
}
