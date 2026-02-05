/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_forks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtawil <mtawil@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 11:08:43 by mtawil            #+#    #+#             */
/*   Updated: 2026/02/05 11:13:26 by mtawil           ###   ########.fr       */
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
    printf("Forks initialized successfullly :D ");
	return (1);
}
