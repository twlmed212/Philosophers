/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtawil <mtawil@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 18:29:16 by mtawil            #+#    #+#             */
/*   Updated: 2026/02/04 21:54:24 by mtawil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int main(int ac, char **av)
{
	if (!check_arguments(ac, av))
		return (1);

	long int milsec = get_time_ms();
	printf("milliseconds passed since 1970 %ld", milsec);
	return (0);
}