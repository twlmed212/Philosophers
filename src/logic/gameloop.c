/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gameloop.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtawil <mtawil@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 16:10:54 by mtawil            #+#    #+#             */
/*   Updated: 2026/02/05 18:38:08 by mtawil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void *game_loop(void *arg)
{
	t_philo *philo = (t_philo *)arg;
	int left_fork;
	int right_fork;

	left_fork = take_left_fork(philo);
	right_fork = take_right_fork(philo);

	philo->last_time_eat = philo->data->start_time;
	while (1)
	{
		// simplte testing semulation
		pthread_mutex_lock(&philo->data->forks[left_fork]);
		print_logs(philo, "Took left fork");
		
		pthread_mutex_lock(&philo->data->forks[right_fork]);
		print_logs(philo, "Took right fork");

		// eating time
		print_logs(philo, "start eating");
		philo->last_time_eat = get_time_ms();
		philo->total_eats++;
		ft_sleep(philo->data->time_to_eat);

		// put down forks
		pthread_mutex_unlock(&philo->data->forks[left_fork]);
		pthread_mutex_unlock(&philo->data->forks[right_fork]);
		// sleeping time
		print_logs(philo, "sleeping");
		ft_sleep(philo->data->time_to_sleep);

		print_logs(philo, "Thinking");
	}
	return (NULL);
}