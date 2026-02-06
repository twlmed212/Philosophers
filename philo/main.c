/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtawil <mtawil@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 18:29:16 by mtawil            #+#    #+#             */
/*   Updated: 2026/02/06 03:45:15 by mtawil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	main(int ac, char **av)
{
	t_data	*data;
	int		i;

	data = parse_arguments(ac, av);
	if (!data)
	{
		free_grabage();
		return (1);
	}
	if (!init_philos(data) || !init_forks(data) || !init_mutex(data))
	{
		free_grabage();
		return (1);
	}
	data->start_time = get_time_ms();
	data->someone_died = 0;
	i = 0;
	while (i < data->nmbr_philos)
	{
		data->philos[i].last_time_eat = data->start_time;
		i++;
	}
	if (data->must_eat_count == 0)
	{
		destroy_mutex(data);
		free_grabage();
		return (0);
	}
	// Create philosopher threads
	i = 0;
	while (i < data->nmbr_philos)
	{
		if (pthread_create(&data->philos[i].thread, NULL, game_loop,
				&data->philos[i]) != 0)
		{
			printf("Error: Failed to create philosopher thread %d\n", i + 1);
			free_grabage();
			return (1);
		}
		i++;
	}
	if (pthread_create(&data->listening_for_deaths, NULL, listening_for_deaths,
			data) != 0)
	{
		printf("Error: Failed to create monitor thread\n");
		free_grabage();
		return (1);
	}
	pthread_join(data->listening_for_deaths, NULL);
	i = 0;
	while (i < data->nmbr_philos)
	{
		pthread_join(data->philos[i].thread, NULL);
		i++;
	}
	destroy_mutex(data);
	free_grabage();
	return (0);
}
