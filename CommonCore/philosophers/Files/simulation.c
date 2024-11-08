/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emedeiro <emedeiro@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 13:17:07 by emedeiro          #+#    #+#             */
/*   Updated: 2024/11/08 13:17:07 by emedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

void *start_simulation(void *ptr)
{
    t_philo *philo = (t_philo *)ptr;

    if (philo->id_philo % 2 == 0)
        ft_usleep(1);
    initialize_philo_times(philo);
    while (true)
        philo_routine(philo);
    return NULL;
}

void initialize_philo_times(t_philo *philo)
{
    long current_time;
    
    pthread_mutex_lock(philo->mutexes.meal_lock);
    current_time = current_time();
    philo->times.last_meal = current_time;
    pthread_mutex_unlock(philo->mutexes.meal_lock);
}
void	print_action(t_philo *philo, char *action)
{
	size_t	time;

	pthread_mutex_lock(philo->mutexes.write_lock);
	time = current_time() - philo->times.born_time;
	printf(GREEN"[%ld]"RESET" %d%s\n", time, philo->id, action);
	pthread_mutex_unlock(philo->mutexes.write_lock);
}

void	philo_routine(t_philo *philo)
{
	pthread_mutex_lock(philo->mutexes.left_fork);
	print_action(philo, " has taken a fork");
	pthread_mutex_lock(philo->mutexes.right_fork);
	print_action(philo, " has taken a fork");
	pthread_mutex_lock(philo->mutexes.meal_lock);
	print_action(philo, " is eating");
	philo->times.last_meal = current_time();
	philo->meals_eaten += 1;
	pthread_mutex_unlock(philo->mutexes.meal_lock);
	ft_usleep(philo->times.eat);
	pthread_mutex_unlock(philo->mutexes.left_fork);
	pthread_mutex_unlock(philo->mutexes.right_fork);
	print_action(philo, " is sleeping");
	ft_usleep(philo->times.sleep);
	print_action(philo, " is thinking");
}
