/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philos.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtawil <mtawil@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 11:50:32 by mtawil            #+#    #+#             */
/*   Updated: 2026/02/05 12:18:03 by mtawil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int init_philos(t_data *data)
{
    int i;

    data->philos = ft_malloc(sizeof(t_philo) * data->nmbr_philos);
    
    i = 0;
    while(i < data->nmbr_philos)
    {
        data->philos[i].id = i + 1;
        data->philos[i].total_eats = 0;
        data->philos[i].last_time_eat = 0;
        
        data->philos[i].data = data;
        
        /* Steps of creating threads
            1- pthread var_to_store_id
            2- pthread_create(var_to.., NULL, func_run, NULL)/// last null for argmunts
            3- pthread join(var, null)
        */        
       i++;
    }

    return (1);
}
