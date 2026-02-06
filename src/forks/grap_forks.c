/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grap_forks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtawil <mtawil@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 16:47:20 by mtawil            #+#    #+#             */
/*   Updated: 2026/02/06 02:33:44 by mtawil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void take_forks(t_philo *philo)
{
    pthread_mutex_lock(&philo->data->forks[philo->id - 1]);
    print_logs(philo, "has taken a left fork");
    pthread_mutex_lock(&philo->data->forks[philo->id % philo->data->nmbr_philos]);
    print_logs(philo, "has taken a right fork");
}

void drop_forks(t_philo *philo)
{
    pthread_mutex_unlock(&philo->data->forks[philo->id - 1]);
    pthread_mutex_unlock(&philo->data->forks[philo->id % philo->data->nmbr_philos]);
}