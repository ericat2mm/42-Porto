/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emedeiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 18:04:11 by emedeiro          #+#    #+#             */
/*   Updated: 2024/10/28 22:52:30 by emedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>
# include <pthread.h>

# define ERR_USAGE "Usage: ./philo <# philosophers> <time to die> <time to \
                     eat> <time to sleep> [# times each philosopher must eat]\n"
#define ERR_FORKS "Error: Forks initialization failed\n"
#define ERR_PHILO "Error: Philo initialization failed\n"
#define ERR_MALLOC "Error: malloc failed\n"
#define ERR_THREAD "Error: thread creation failed\n"
#define ERR_MUTEX "Error: mutex creation failed\n"
#define ERR_TIME "Error: gettimeofday failed\n"
#define ERR_USLEEP "Error: usleep failed\n"
#define ERR_JOIN "Error: thread join failed\n"
#define ERR_DESTROY "Error: mutex destroy failed\n"
#define ERR_INIT "Error: mutex init failed\n"
#define ERR_LOCK "Error: mutex lock failed\n"
#define ERR_UNLOCK "Error: mutex unlock failed\n"

# define RESET    "\033[0m"
# define RED      "\033[31m"    /* Red */
# define GREEN    "\033[32m"    /* Green */


typedef struct s_mutexes
{
    pthread_mutex_t *left_fork;
    pthread_mutex_t *right_fork;
    pthread_mutex_t *meal_lock;
}   t_mutexes;

typedef struct s_time
{
    int die;
    int eat;
    int sleep;
    int last_meal;
}   t_time;

typedef struct s_philo
{
    int id_philo;
    t_time times;
    t_mutexes mutexes;
    int need_to_eat;
    int meals_eaten;
    int philo_count;
}   t_philo;

typedef struct philo_data
{
    pthread_mutex_t  *forks;
    t_philo *philos;
    pthread_mutex_t  meal_lock;    
}   t_philo_data;


#endif