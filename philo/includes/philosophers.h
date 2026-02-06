/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtawil <mtawil@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 18:28:51 by mtawil            #+#    #+#             */
/*   Updated: 2026/02/06 13:53:27 by mtawil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>

typedef struct s_philo
{
	int				id;
	int				total_eats;
	long			last_time_eat;

	pthread_t		thread;
	pthread_mutex_t	*last_time_eat_mutex;

	struct s_data	*data;

}					t_philo;

typedef struct s_data
{
	int				nmbr_philos;
	long			time_to_die;
	long			time_to_eat;
	long			time_to_sleep;
	int				must_eat_count;

	long			start_time;
	int				someone_died;

	pthread_mutex_t	*forks;
	pthread_mutex_t	*print_mutex;
	pthread_mutex_t	*death_mutex;
	pthread_t		listening_for_deaths;

	t_philo			*philos;
}					t_data;

typedef struct s_gc
{
	void			*data;
	struct s_gc		*next;
}					t_gc;

// GameLooop Logic
void				*game_loop(void *arg);
void				*listening_for_deaths(void *agr);

// Managing Philos
int					init_philos(t_data *data);

// Managing Mutex
int					init_mutex(t_data *data);

// Managing Forks
int					init_forks(t_data *data);
void				destroy_mutex(t_data *data);
void				take_forks(t_philo *philo);
void				drop_forks(t_philo *philo);

//  Arguments
int					check_arguments(char *argv);
t_data				*parse_arguments(int argc, char **argv);

// Utils Helper function
int					ft_strlen(char *str);
int					print_error(char *str);
long				ft_atoi(char *str);
void				print_logs(t_philo *philo, char *log);

// Time Helper functions
long int			get_time_ms(void);
long				get_timestamp(long start_time);
void				ft_sleep(long ms);

// Garbage collector
t_gc				*create_node(void *data);
t_gc				*get_garbage_collecter(void *ptr);
void				*ft_malloc(size_t size);
void				free_grabage(void);

#endif