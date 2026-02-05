/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gameloop.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtawil <mtawil@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 16:10:54 by mtawil            #+#    #+#             */
/*   Updated: 2026/02/05 16:40:31 by mtawil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void *game_loop(void *arg)
{
    t_philo *philo = (t_philo *)arg;
    int testing = 0;
    while (testing < 3)
    {
        // simplte testing semulation
     print_logs(philo, "Took left fork");
     print_logs(philo, "Took right fork");
        
    // eating time
     print_logs(philo, "start eating");
     philo->last_time_eat = get_time_ms();
     philo->total_eats++;
     ft_sleep(philo->data->time_to_eat);
     
     // put down forks
     
     // sleeping tiem
    print_logs(philo, "sleeping");
     ft_sleep(philo->data->time_to_sleep);

     testing++;
    }
    return (NULL);
}