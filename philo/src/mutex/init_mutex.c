/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mutex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtawil <mtawil@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 19:53:09 by mtawil            #+#    #+#             */
/*   Updated: 2026/02/06 17:47:08 by mtawil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	init_mutex(t_data *data)
{
	int	i;

	data->print_mutex = ft_malloc(sizeof(pthread_mutex_t));
	pthread_mutex_init(data->print_mutex, NULL);
	data->death_mutex = ft_malloc(sizeof(pthread_mutex_t));
	pthread_mutex_init(data->death_mutex, NULL);
	i = 0;
	while (i < data->nmbr_philos)
	{
		data->philos[i].last_time_eat_mutex
			= ft_malloc(sizeof(pthread_mutex_t));
		pthread_mutex_init(data->philos[i].last_time_eat_mutex, NULL);
		i++;
	}
	return (1);
}
