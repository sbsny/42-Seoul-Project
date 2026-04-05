/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonyun <seonyun@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 05:10:30 by seonyun           #+#    #+#             */
/*   Updated: 2022/11/19 18:07:11 by seonyun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long	get_timestamp_ms(void)
{
	struct timeval	tp;

	gettimeofday(&tp, NULL);
	return (tp.tv_sec * 1000 + tp.tv_usec / 1000);
}

int	sleep_with_monitoring(long s_time, t_philo *ph)
{
	long	sleep_start;
	long	current_time;

	sleep_start = get_timestamp_ms();
	current_time = sleep_start;
	while (sleep_start + s_time > current_time)
	{
		if (*(ph->is_alive) == false)
			return (1);
		if (ph->config->time_to_die_ms < (current_time - ph->config->start_timestamp
				- ph->last_meal_time))
		{
			pthread_mutex_lock(ph->death_mutex);
			print_status(ph, "died");
			*(ph->is_alive) = false;
			pthread_mutex_unlock(ph->death_mutex);
			return (1);
		}
		usleep(150);
		current_time = get_timestamp_ms();
	}
	return (0);
}

int	free_philosopher_data(t_philo *ph)
{
	int	i;
	int	philo;

	i = 0;
	philo = ph[0].config->philo_count;
	while (i < philo)
	{
		if (ph[i].right_fork_mutex != NULL)
			free(ph[i].right_fork_mutex);
		i++;
	}
	if (ph->is_alive != NULL)
		free(ph->is_alive);
	if (ph->print_mutex != NULL)
		free(ph->print_mutex);
	if (ph->death_mutex != NULL)
		free(ph->death_mutex);
	if (ph != NULL)
		free(ph);
	return (0);
}
