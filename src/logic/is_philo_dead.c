/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_philo_dead.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtawil <mtawil@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 19:47:35 by mtawil            #+#    #+#             */
/*   Updated: 2026/02/05 20:19:45 by mtawil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static int is_philos_dead(t_philo *philo)
{
    long time_now;
    long last_eat;
    long diffrent;

    time_now = get_time_ms();

    pthread_mutex_lock(philo->last_time_eat_mutex);
    last_eat = philo->last_time_eat;
    pthread_mutex_unlock(philo->last_time_eat_mutex);

    diffrent = time_now - last_eat;

    if (diffrent > philo->data->time_to_die)
    {
        pthread_mutex_lock(philo->data->print_mutex);
    
		long timestamp = get_timestamp(philo->data->start_time);
		printf("%ld %d died\n", timestamp, philo->id);
    
		pthread_mutex_unlock(philo->data->print_mutex);
        return (1);
    }
    return (0);
}

void *listening_for_deaths(void *agr)
{
    t_data *data = (t_data *) agr;
    int i;

    
    while(1)
    {
        i  = 0;
        while(i < data->nmbr_philos)
        {
            if (is_philos_dead(&data->philos[i]))
            {
                pthread_mutex_lock(data->death_mutex);
                data->someone_died = 1;
                pthread_mutex_unlock(data->death_mutex);
                return (NULL);
            }
            i++;
        }
        usleep(1000);
    }
}