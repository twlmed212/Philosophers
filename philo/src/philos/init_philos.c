/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philos.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtawil <mtawil@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 11:50:32 by mtawil            #+#    #+#             */
/*   Updated: 2026/02/06 13:57:57 by mtawil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	init_philos(t_data *data)
{
	int	i;

	data->philos = ft_malloc(sizeof(t_philo) * data->nmbr_philos);
	i = 0;
	while (i < data->nmbr_philos)
	{
		data->philos[i].id = i + 1;
		data->philos[i].total_eats = 0;
		data->philos[i].last_time_eat = 0;
		data->philos[i].data = data;
		i++;
	}
	return (1);
}
