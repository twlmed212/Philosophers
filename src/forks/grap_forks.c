/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grap_forks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtawil <mtawil@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 16:47:20 by mtawil            #+#    #+#             */
/*   Updated: 2026/02/06 03:37:08 by mtawil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void take_forks(t_philo *philo)
{
    int	left;
    int	right;

    left = philo->id - 1;
    right = philo->id % philo->data->nmbr_philos;
    if (philo->data->nmbr_philos == 1)
    {
        pthread_mutex_lock(&philo->data->forks[left]);
        print_logs(philo, "has taken a fork");
        return ;
    }
    if (philo->id % 2 == 0)
    {
        pthread_mutex_lock(&philo->data->forks[left]);
        print_logs(philo, "has taken a fork");
        pthread_mutex_lock(&philo->data->forks[right]);
        print_logs(philo, "has taken a fork");
    }
    else
    {
        pthread_mutex_lock(&philo->data->forks[right]);
        print_logs(philo, "has taken a fork");
        pthread_mutex_lock(&philo->data->forks[left]);
        print_logs(philo, "has taken a fork");
    }
}

void drop_forks(t_philo *philo)
{
    pthread_mutex_unlock(&philo->data->forks[philo->id - 1]);
    pthread_mutex_unlock(&philo->data->forks[philo->id % philo->data->nmbr_philos]);
}