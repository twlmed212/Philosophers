/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtawil <mtawil@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 18:34:43 by mtawil            #+#    #+#             */
/*   Updated: 2026/02/06 13:59:07 by mtawil           ###   ########.fr       */
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
	if (!is_valid_nmbr(argv) || ft_atoi(argv) == -1)
	{
		printf("Error: '%s' is not valid argument\n", argv);
		return (0);
	}
	
	return (1);
}
