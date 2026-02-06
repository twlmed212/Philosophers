/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_philo_dead.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtawil <mtawil@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 19:47:35 by mtawil            #+#    #+#             */
/*   Updated: 2026/02/06 17:51:02 by mtawil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static int	is_philos_dead(t_philo *philo)
{
	long	time_now;
	long	last_eat;
	long	diffrent;

	time_now = get_time_ms();
	pthread_mutex_lock(philo->last_time_eat_mutex);
	last_eat = philo->last_time_eat;
	pthread_mutex_unlock(philo->last_time_eat_mutex);
	diffrent = time_now - last_eat;
	if (diffrent > philo->data->time_to_die)
	{
		pthread_mutex_lock(philo->data->print_mutex);
		printf("%ld %d died\n", get_timestamp(philo->data->start_time),
			philo->id);
		pthread_mutex_lock(philo->data->death_mutex);
		philo->data->someone_died = 1;
		pthread_mutex_unlock(philo->data->death_mutex);
		pthread_mutex_unlock(philo->data->print_mutex);
		return (1);
	}
	return (0);
}

static int	check_all_eats(t_data *data)
{
	int		i;
	int		eats;

	if (data->must_eat_count == -1)
		return (0);
	i = 0;
	while (i < data->nmbr_philos)
	{
		pthread_mutex_lock(data->philos[i].last_time_eat_mutex);
		eats = data->philos[i].total_eats;
		pthread_mutex_unlock(data->philos[i].last_time_eat_mutex);
		if (eats < data->must_eat_count)
			return (0);
		i++;
	}
	return (1);
}

void	*listening_for_deaths(void *agr)
{
	int			i;
	t_data		*data;

	data = (t_data *)agr;
	while (1)
	{
		i = 0;
		while (i < data->nmbr_philos)
		{
			if (is_philos_dead(&data->philos[i]))
				return (NULL);
			i++;
		}
		if (check_all_eats(data))
		{
			pthread_mutex_lock(data->death_mutex);
			data->someone_died = 1;
			pthread_mutex_unlock(data->death_mutex);
			return (NULL);
		}
		usleep(1000);
	}
}
