/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grap_forks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtawil <mtawil@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 16:47:20 by mtawil            #+#    #+#             */
/*   Updated: 2026/02/05 16:48:25 by mtawil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int take_left_fork(t_philo *philo)
{
    return (philo->id - 1);
}

int take_right_fork(t_philo *philo)
{
    return (philo->id % philo->data->nmbr_philos);
}