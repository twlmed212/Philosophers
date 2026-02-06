/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gameloop.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtawil <mtawil@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 16:10:54 by mtawil            #+#    #+#             */
/*   Updated: 2026/02/06 13:48:59 by mtawil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static int stop(t_philo *philo)
{
    int dead;
    
    pthread_mutex_lock(philo->data->death_mutex);
    dead = philo->data->someone_died;
    pthread_mutex_unlock(philo->data->death_mutex);
    
    return (dead);
}

static void	do_think(t_philo *philo)
{
    long	think_time;

    print_logs(philo, "is thinking");
    think_time = philo->data->time_to_die
        - philo->data->time_to_eat - philo->data->time_to_sleep;
    if (think_time > 10)
        ft_sleep(think_time - 10);
}

void *game_loop(void *arg)
{
    t_philo *philo = (t_philo *)arg;

    if (philo->id % 2 == 0)
        usleep(1000);
    while (!stop(philo))
    {
        take_forks(philo);
        if (philo->data->nmbr_philos == 1)
        {
            drop_forks(philo);
            break ;
        }
        print_logs(philo, "is eating");
        pthread_mutex_lock(philo->last_time_eat_mutex);
        philo->last_time_eat = get_time_ms();
        pthread_mutex_unlock(philo->last_time_eat_mutex);
        ft_sleep(philo->data->time_to_eat);
        pthread_mutex_lock(philo->last_time_eat_mutex);
        philo->total_eats++;
        pthread_mutex_unlock(philo->last_time_eat_mutex);
        drop_forks(philo);
        print_logs(philo, "is sleeping");
        ft_sleep(philo->data->time_to_sleep);
        do_think(philo);
    }
    return (NULL);
}