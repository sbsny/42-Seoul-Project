/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonyun <seonyun@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 05:10:14 by seonyun           #+#    #+#             */
/*   Updated: 2022/11/19 18:11:10 by seonyun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include	<unistd.h>
# include	<stdio.h>
# include	<pthread.h>
# include	<stdlib.h>
# include	<stdbool.h>
# include	<sys/time.h>

typedef struct s_args
{
	int		philo_count;
	int		time_to_die_ms;
	int		time_to_eat_ms;
	int		time_to_sleep_ms;
	int		meals_required;
	long	start_timestamp;
}	t_args;

typedef struct s_philo
{
	t_args			*config;
	pthread_mutex_t	*right_fork_mutex;
	pthread_mutex_t	*left_fork_mutex;
	pthread_mutex_t	*print_mutex;
	pthread_mutex_t	*death_mutex;
	pthread_t		thread_id;
	long			last_meal_time;
	int				philo_id;
	int				meal_count;
	bool			*is_alive;
}	t_philo;

long	get_timestamp_ms(void);
int		parse_int(const char *str);
int		validate_input(int ac, char **av);
void	parse_arguments(t_args *config, int ac, char **av);

t_philo	*allocate_philosophers(t_args *config);
int		initialize_philosophers(t_philo *ph, t_args *config, int start_idx);
int		join_and_destroy(t_philo *philo, int philo_count);
int		free_philosopher_data(t_philo *philo);

int		sleep_with_monitoring(long sleep_time, t_philo *philo);
void	print_status(t_philo *philo, const char *status_msg);
void	*run_philosopher_cycle(void *philo_ptr);

#endif
