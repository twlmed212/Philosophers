/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_forks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtawil <mtawil@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 11:08:43 by mtawil            #+#    #+#             */
/*   Updated: 2026/02/05 19:51:39 by mtawil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	init_forks(t_data *data)
{
	int i;
	
	data->forks = ft_malloc(sizeof(pthread_mutex_t) * data->nmbr_philos);
	
	i = 0;
	while (i < data->nmbr_philos)
	{
        if (pthread_mutex_init(&data->forks[i], NULL) != 0)
		{
            print_error("Error: Init forks..");
			return (0);
		}
		i++;
	}
	return (1);
}

void destroy_mutex(t_data *data) {
    int i;

    i = 0;
    while (i < data->nmbr_philos)
	{
		pthread_mutex_destroy(&data->forks[i]);
        i++;
    }
	pthread_mutex_destroy(data->print_mutex);

}