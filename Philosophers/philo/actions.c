/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonyun <seonyun@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 05:10:52 by seonyun           #+#    #+#             */
/*   Updated: 2022/11/19 18:07:07 by seonyun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int sleeping(t_philo *ph)
{
	if (*(ph->is_alive) == true)
		print_status(ph, "is sleeping");
	if (sleep_with_monitoring(ph->config->time_to_sleep_ms, ph))
		return (1);
	return (0);
}

int eating(t_philo *ph)
{
	pthread_mutex_lock(ph->left_fork_mutex);
	if (*(ph->is_alive) == true)
		print_status(ph, "has taken a fork");
	pthread_mutex_lock(ph->right_fork_mutex);
	if (*(ph->is_alive) == true)
		print_status(ph, "has taken a fork");
	if (*(ph->is_alive) == true)
		print_status(ph, "is eating");
	if (sleep_with_monitoring(ph->config->time_to_eat_ms, ph))
	{
		pthread_mutex_unlock(ph->right_fork_mutex);
		pthread_mutex_unlock(ph->left_fork_mutex);
		return (1);
	}
	ph->last_meal_time = get_timestamp_ms() - ph->config->start_timestamp;
	pthread_mutex_unlock(ph->right_fork_mutex);
	pthread_mutex_unlock(ph->left_fork_mutex);
	ph->meal_count++;
	return (0);
}

int thinking(t_philo *ph)
{
	if (*(ph->is_alive) == true)
		print_status(ph, "is thinking");
	if (ph->meal_count == 0)
	{
		if (sleep_with_monitoring(100, ph))
			return (1);
	}
	return (0);
}

void *run_philosopher_cycle(void *ph)
{
	t_philo *philo;

	philo = (t_philo *)ph;
	if (philo == NULL || philo->config->philo_count == 1)
		return (NULL);
	if (philo->philo_id % 2 == 1)
		thinking(philo);
	while (1)
	{
		if (eating(philo))
			break;
		if (philo->meal_count == philo->config->meals_required)
			break;
		if (sleeping(philo))
			break;
		if (thinking(philo))
			break;
	}
	return (NULL);
}
