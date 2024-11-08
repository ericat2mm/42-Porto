/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emedeiro <emedeiro@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 13:02:51 by emedeiro          #+#    #+#             */
/*   Updated: 2024/11/08 13:02:51 by emedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

void launcher(t_philo_data *sim, int count)
{
    pthread_t monitor_thread_id;
    int i;

    if (pthread_create(&monitor_thread_id, NULL, &monitor_simulation, sim->philos) != 0)
        destroy_all(sim, "[Thread Creation ERROR - Observer]\n", count, 1);
    i = -1;
    while (++i < count)
    {
        if (pthread_create(&sim->philos[i].thread_id, NULL,
                start_simulation, &sim->philos[i]) != 0)
            destroy_all(sim, "[Thread Creation ERROR - Philosopher]\n", count, 1);
    }
    if (pthread_join(monitor_thread_id, NULL) != 0)
        destroy_all(sim, "[Thread Join ERROR - Observer]\n", count, 1);
    i = -1;
    while (i < count)
    {
        if (pthread_detach(sim->philos[i].thread_id) != 0)
            destroy_all(sim, "[Thread Detach ERROR - Philosopher]\n", count, 1);
    }
}

void	*monitor_simulation(void *ptr)
{
	t_philo	*philos;
	int		i;

	philos = (t_philo *)ptr;
	while (true)
	{
		i = -1;
		while (++i < philos[0].philo_count)
		{
			pthread_mutex_lock(philos->mutexes.meal_lock);
			if (current_time() - philos[i].times.last_meal
				> philos[i].times.die)
			{
				pthread_mutex_unlock(philos->mutexes.meal_lock);
				print_thread(&philos[i], RED" died"RESET);
				pthread_mutex_lock(philos->mutexes.write_lock);
				return (NULL);
			}
			pthread_mutex_unlock(philos->mutexes.meal_lock);
		}
		if (is_all_eat(philos))
			return (NULL);
	}
	return (NULL);
}
bool	is_all_eat(t_philo *philos)
{
	int		finished;
	int		i;

	i = -1;
	finished = 0;
	if (philos[0].must_eat == -1)
		return (false);
	while (++i < philos[0].philo_count)
	{
		pthread_mutex_lock(philos->mutexes.meal_lock);
		if (philos[i].meals_eaten >= philos[i].must_eat)
			++finished;
		pthread_mutex_unlock(philos->mutexes.meal_lock);
	}
	if (finished == philos[0].philo_count)
	{
		pthread_mutex_lock(philos->mutexes.write_lock);
		return (true);
	}
	return (false);
}
