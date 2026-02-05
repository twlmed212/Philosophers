/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtawil <mtawil@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 18:29:16 by mtawil            #+#    #+#             */
/*   Updated: 2026/02/05 19:25:07 by mtawil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int main(int ac, char **av)
{
    t_data *data;
	data = parse_arguments(ac, av);
	if (!data)
	{
		free_grabage();
		return (1);
	}

	printf("%d\n", data->nmbr_philos);
	printf("%ld\n", data->time_to_die);
	printf("%ld\n", data->time_to_eat);
	printf("%ld\n", data->time_to_sleep);
	printf("%d\n", data->must_eat_count);
	if (!init_philos(data))
	{
		printf("Forks faileds :/:D\n");
		return (1);
	}
	init_forks(data);
	data->print_mutex = ft_malloc(sizeof(pthread_mutex_t));
	pthread_mutex_init(data->print_mutex, NULL);
	for (int i = 0; i < data->nmbr_philos; i++ ) {
		data->start_time = get_time_ms();
		int err = pthread_create(&data->philos[i].thread, NULL, game_loop, &data->philos[i]);
		if (err != 0){
			// free anything allocated and exit the program
			exit(12);
		}
	}
	for (int i = 0; i < data->nmbr_philos; i++ ) {
		printf("waitng\n");
		int err = pthread_join(data->philos->thread, NULL);
		if (err != 0){
			// free anything allocated and exit the program
			exit(12);
		}
	}
	destroy_mutex(data);
	return (0);
}