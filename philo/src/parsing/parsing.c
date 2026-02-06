/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtawil <mtawil@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 10:47:31 by mtawil            #+#    #+#             */
/*   Updated: 2026/02/06 18:00:16 by mtawil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static t_data	*fill_shared_data(int argc, char **argv)
{
	t_data	*data;

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

t_data	*parse_arguments(int argc, char **argv)
{
	int		i;

	i = 1;
	if (argc < 5 || argc > 6)
	{
		print_error("Please Provide 4 or 5 arguments\n");
		print_error("Ex: ./philo number_of_philosophers ");
		print_error("time_to_die time_to_eat time_to_sleep  ");
		print_error("[number_of_times_each_philosopher_must_eat]\n");
		return (NULL);
	}
	while (i < argc)
	{
		if (!check_arguments(argv[i]))
			return (NULL);
		i++;
	}
	return (fill_shared_data(argc, argv));
}
