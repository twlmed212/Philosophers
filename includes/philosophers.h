/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtawil <mtawil@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 18:28:51 by mtawil            #+#    #+#             */
/*   Updated: 2026/02/05 10:08:00 by mtawil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
#define PHILOSOPHERS_H

# include <stdio.h>
# include <pthread.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>


typedef struct s_philo{
    int id;
    int total_eats;
    long last_time_eat;
    
    struct s_data *data;
} t_philo;


typedef struct s_data {
    int nmbr_philos;
    long time_to_die;
    long time_to_eat;
    long time_to_sleep;
	int must_eat_count;

    long start_time;
    int did_any_one_died;

    pthread_mutex_t *forks;
    pthread_mutex_t *print_mutex;
    pthread_mutex_t *death_mutex;

    t_philo *philos;
} t_data;


typedef struct s_gc
{
	void				*data;
	struct s_gc			*next;
}						t_gc;

//  Arguments
int	check_arguments(int argc, char **argv);

// Utils Helper function
int ft_strlen(char *str);
int print_error(char *str);
int	ft_atoi(char *str);

// Time Helper functions
long int get_time_ms();
long	get_timestamp(long start_time);
void	ft_sleep(long ms);

// Garbage collector
t_gc	*create_node(void *data);
t_gc	*get_garbage_collecter(void *ptr);
void	*ft_malloc(size_t size);
void	free_grabage(void);


#endif