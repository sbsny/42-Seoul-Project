/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_op.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonyun <seonyun@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 05:10:37 by seonyun           #+#    #+#             */
/*   Updated: 2022/11/19 18:25:08 by seonyun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	initialize_philosophers(t_philo *ph, t_args *config, int i)
{
	while (i < config->philo_count)
	{
		ph[i].right_fork_mutex = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t));
		if (!ph[i].right_fork_mutex || pthread_mutex_init(ph[i].right_fork_mutex, NULL))
			return (1);
		i++;
	}
	i = 0;
	while (i < config->philo_count)
	{
		ph[i].philo_id = i + 1;
		ph[i].left_fork_mutex = ph[(i + 1) % config->philo_count].right_fork_mutex;
		ph[i].is_alive = ph[0].is_alive;
		ph[i].print_mutex = ph[0].print_mutex;
		ph[i].death_mutex = ph[0].death_mutex;
		ph[i].config = config;
		ph[i].last_meal_time = 0;
		ph[i].meal_count = 0;
		if (pthread_create(&ph[i].thread_id, NULL, &run_philosopher_cycle, (void *)&ph[i]))
			return (1);
		i++;
	}
	return (0);
}

t_philo	*allocate_philosophers(t_args *config)
{
	t_philo	*philo;

	philo = (t_philo *)malloc(sizeof(t_philo) * (config->philo_count));
	philo->is_alive = (bool *)malloc(sizeof(bool));
	philo->print_mutex = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t));
	philo->death_mutex = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t));
	if (!philo || !philo->is_alive || !philo->print_mutex || !philo->death_mutex)
		return (NULL);
	*(philo->is_alive) = true;
	if (pthread_mutex_init(philo->print_mutex, NULL))
		return (NULL);
	if (pthread_mutex_init(philo->death_mutex, NULL))
		return (NULL);
	if (initialize_philosophers(philo, config, 0))
		return (NULL);
	return (philo);
}

int	join_and_destroy(t_philo *philo, int ph)
{
	int		i;

	i = 0;
	while (i < ph)
	{
		if (pthread_join(philo[i].thread_id, NULL))
			return (1);
		pthread_mutex_destroy(philo[i].right_fork_mutex);
		i++;
	}
	pthread_mutex_destroy(philo->print_mutex);
	pthread_mutex_destroy(philo->death_mutex);
	return (0);
}

void	print_status(t_philo *ph, const char *status_msg)
{
	pthread_mutex_lock(ph->print_mutex);
	printf("%ld\t", get_timestamp_ms() - ph->config->start_timestamp);
	printf("%d\t%s\n", ph->philo_id, status_msg);
	pthread_mutex_unlock(ph->print_mutex);
}
