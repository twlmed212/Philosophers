/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logs.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtawil <mtawil@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 16:07:42 by mtawil            #+#    #+#             */
/*   Updated: 2026/02/05 17:45:28 by mtawil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void print_logs(t_philo *philo, char *log)
{
	long timenow;

	pthread_mutex_lock(&philo->data->print_mutex);

	timenow = get_timestamp(philo->data->start_time);
	printf("%ld %d %s\n", timenow, philo->id, log);
	
	pthread_mutex_unlock(&philo->data->print_mutex);

}