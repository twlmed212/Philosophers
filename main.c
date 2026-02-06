/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtawil <mtawil@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 18:29:16 by mtawil            #+#    #+#             */
/*   Updated: 2026/02/06 02:47:33 by mtawil           ###   ########.fr       */
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
	if (!init_philos(data))
	{
		//todo free memory
		printf("Forks faileds :/:D\n");
		return (1);
	}
	init_forks(data);
	init_mutex(data);
	for (int i = 0; i < data->nmbr_philos; i++ ) {
		data->start_time = get_time_ms();
		int err = pthread_create(&data->philos[i].thread, NULL, game_loop, &data->philos[i]);
		if (err != 0){
			// free anything allocated and exit the program
			exit(12);
		}
	}

	int err = pthread_create(&data->listening_for_deaths, NULL, listening_for_deaths, data);
	if (err != 0){
		// free anything allocated and exit the program
		exit(12);
	}

		
	for (int i = 0; i < data->nmbr_philos; i++ ) {
		int err = pthread_join(data->philos->thread, NULL);
		if (err != 0){
			// free anything allocated and exit the program
			exit(12);
		}
	}
	destroy_mutex(data);
	free_grabage();
	return (0);
}