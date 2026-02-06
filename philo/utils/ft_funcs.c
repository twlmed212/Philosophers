/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_funcs.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtawil <mtawil@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 09:54:54 by mtawil            #+#    #+#             */
/*   Updated: 2026/02/06 14:17:42 by mtawil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int ft_strlen(char *str) {
    int i = 0;
    while(str[i]){
        i++;
    }
    return (i);
}

long	ft_atoi(char *str)
{
	long	result;
	int	i;

	i = 0;
	result = 0;
	while (str[i] == ' '
		|| (str[i] >= 9 && str[i] <= 13))
	{
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = (result * 10) + (str[i] - '0');
		if (result > 2147483647)
		{
			printf("number is long\n");
			return (-1);
		}
		i++;
	}
	return (result);
}