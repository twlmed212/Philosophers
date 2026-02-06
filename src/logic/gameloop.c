/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gameloop.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtawil <mtawil@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 16:10:54 by mtawil            #+#    #+#             */
/*   Updated: 2026/02/06 02:38:00 by mtawil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"


static int	stop(t_philo *philo)
{
	int dead = 0;
	
	pthread_mutex_lock(philo->data->death_mutex);
	dead = philo->data->someone_died;
	pthread_mutex_unlock(philo->data->death_mutex);
	
	return (dead);
}

void *game_loop(void *arg)
{
	t_philo *philo = (t_philo *)arg;

	pthread_mutex_lock(philo->last_time_eat_mutex);
	philo->last_time_eat = philo->data->start_time;
	pthread_mutex_unlock(philo->last_time_eat_mutex);
	
	while (!stop(philo))
	{
		// simplte testing semulation
        // take_forks
        take_forks(philo);

		// eating time
		print_logs(philo, "start eating");
		philo->last_time_eat = get_time_ms();
		philo->total_eats++;
		ft_sleep(philo->data->time_to_eat);

		// put down forks
        // drop_forks
        drop_forks(philo);
		// sleeping time
		print_logs(philo, "sleeping");
		ft_sleep(philo->data->time_to_sleep);

		print_logs(philo, "Thinking");
	}
	return (NULL);
}

