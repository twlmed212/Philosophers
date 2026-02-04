/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arguments.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtawil <mtawil@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 18:34:43 by mtawil            #+#    #+#             */
/*   Updated: 2026/02/04 19:00:35 by mtawil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

int check_arguments(int ac) {
    if (ac != 5){
        print_error("Please Provide at least 4 Arguments\n");
        print_error("Ex: ./program 5 800 200 200\n");
        print_error("1: number_of_philosophers");
        print_error("2: time_to_die");
        print_error("3: time_to_eat");
        print_error("4: time_to_sleep");
        print_error("5: [number_of_times_each_philosopher_must_eat] (Optional)");
        return (0);
    }
    return (1);
}