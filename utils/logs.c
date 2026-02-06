/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logs.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtawil <mtawil@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 16:07:42 by mtawil            #+#    #+#             */
/*   Updated: 2026/02/06 14:17:17 by mtawil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int print_error(char *str){
    return write(2, str, ft_strlen(str));
}

void print_logs(t_philo *philo, char *log)
{
	long timenow;
	int died;

	died = 0;
	pthread_mutex_lock(philo->data->print_mutex);

	pthread_mutex_lock(philo->data->death_mutex);
	died = philo->data->someone_died;
	pthread_mutex_unlock(philo->data->death_mutex);

	if (!died){
		timenow = get_timestamp(philo->data->start_time);
		printf("%ld %d %s\n", timenow, philo->id, log);
	}
	
	pthread_mutex_unlock(philo->data->print_mutex);

}