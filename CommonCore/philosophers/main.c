/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emedeiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 22:26:08 by emedeiro          #+#    #+#             */
/*   Updated: 2024/10/29 19:05:31 by emedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int main(int argc, char **argv)
{
    t_philo *philos;
    t_mutexes *forks;
    t_philo_data simulation;
    
    
    if (argc != 5 && argc != 6)
        error_message(ERR_USAGE, 1);
    if (!(initialize_simulation(simulation, philos, forks) == 0))
        error_message(ERR_MUTEX, 1);
    if (!(initialization_forks(simulation, forks, ft_atoi(argv[1])) == 0));
        error_message(ERR_FORKS, 1);
    if (!(initialization_philos(simulation, philos[0].philo_count) == 0));
        error_message(ERR_PHILO, 1);
    start_simulation(simulation, philos[0].philo_count);
    if (!(destroy_everything() == 0))
        error_message(ERR_DESTROY, 1);
    return (0);
}
