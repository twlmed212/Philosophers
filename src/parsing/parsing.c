/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtawil <mtawil@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 10:47:31 by mtawil            #+#    #+#             */
/*   Updated: 2026/02/05 11:19:30 by mtawil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

t_data *parse_arguments(int argc, char **argv)
{
    int i;
    t_data *data;

    i = 1;
    if (argc < 5 || argc > 6){
        print_error("Please Provide 4 or 5 arguments\n");
        print_error("Ex: ./program 5 800 200 200\n");
        return (NULL);
    }
    
    while(i < argc){
        if (!check_arguments(argv[i]))
            return (NULL);
        i++;
    }
    
    data = ft_malloc(sizeof(t_data));
    
    data->nmbr_philos = ft_atoi(argv[1]);
    data->time_to_die = ft_atoi(argv[2]);
    data->time_to_eat = ft_atoi(argv[3]);
    data->time_to_sleep = ft_atoi(argv[4]);
    
    if (argc == 6)
        data->must_eat_count = ft_atoi(argv[5]);
    else
        data->must_eat_count = -1;
    
    return (data);
}
