/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtawil <mtawil@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 18:29:16 by mtawil            #+#    #+#             */
/*   Updated: 2026/02/05 11:36:49 by mtawil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int main(int ac, char **av)
{
    t_data *data;
	data = parse_arguments(ac, av);
	if (!data)
	{
		free_grabage();
		return (1);
	}

	printf("%d\n", data->nmbr_philos);
	printf("%ld\n", data->time_to_die);
	printf("%ld\n", data->time_to_eat);
	printf("%ld\n", data->time_to_sleep);
	printf("%d\n", data->must_eat_count);
	if (!init_forks(data))
	{
		printf("Forks faileds :/:D\n");
		return (1);
	}
	destroy_forks(data);
	return (0);
}