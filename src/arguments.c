/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arguments.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtawil <mtawil@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 18:34:43 by mtawil            #+#    #+#             */
/*   Updated: 2026/02/04 22:00:28 by mtawil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

static int	is_digit(char c)
{
	return (c >= '0' && c <= '9');
}
static int	is_valid_nmbr(char *str)
{
	int i;
	
	if (!str || str[0] == '\0')
		return (0);
	
	i = 0;
	while (str[i])
	{
		if (!is_digit(str[i]))
			return (0);
		i++;
	}
	
	return (1);
}

int	check_arguments(int argc, char **argv)
{
	int i;
	
	i = 1;
    
    if (argc < 5 || argc > 6){
        print_error("Please Provide at least 4 Arguments\n");
        print_error("Ex: ./program 5 800 200 200\n");
        return (0);
    }
	while (i < argc)
	{
		if (!is_valid_nmbr(argv[i]))
		{
			printf("Error: '%s' is not valid argument\n", argv[i]);
			return (0);
		}
		i++;
	}
	
	return (1);
}
