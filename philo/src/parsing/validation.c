/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtawil <mtawil@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 18:34:43 by mtawil            #+#    #+#             */
/*   Updated: 2026/02/06 15:36:35 by mtawil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

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

int	check_arguments(char *argv)
{
	int nmbr;

	nmbr = ft_atoi(argv);
	if (!is_valid_nmbr(argv))
		return (printf("Error: '%s' is not valid argument\n", argv), 0);
	if (nmbr <= 0)
	{
		if (nmbr == 0){
			printf("Error: '%s' enter a number greater than 0.\n", argv);
		}else{
			printf("Error: '%s' is not valid argument\n", argv);
		}
		return (0);
	}
	
	return (1);
}
