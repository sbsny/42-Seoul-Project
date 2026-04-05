/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonyun <seonyun@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 05:10:46 by seonyun           #+#    #+#             */
/*   Updated: 2022/11/19 18:11:10 by seonyun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	parse_int(const char *str)
{
	int	i;
	int	result;
	int	sign;

	i = 0;
	sign = 1;
	result = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n' || str[i] == '\v'
		|| str[i] == '\f' || str[i] == '\r')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -sign;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + str[i] - '0';
		i++;
	}
	return (sign * result);
}

int	validate_input(int ac, char **av)
{
	int	i;
	int	j;

	i = 1;
	if (ac != 5 && ac != 6)
		return (printf("Error\n"));
	while (av[i])
	{
		j = 0;
		if (parse_int(av[i]) <= 0)
			return (printf("Error\n"));
		while (av[i][j])
		{
			if (av[i][j] < '0' || av[i][j] > '9')
				return (printf("Error\n"));
			j++;
		}
		i++;
	}
	return (0);
}

void	parse_arguments(t_args *config, int ac, char **av)
{
	config->start_timestamp = get_timestamp_ms();
	config->philo_count = parse_int(av[1]);
	config->time_to_die_ms = parse_int(av[2]);
	config->time_to_eat_ms = parse_int(av[3]);
	config->time_to_sleep_ms = parse_int(av[4]);
	if (ac == 6)
		config->meals_required = parse_int(av[5]);
	else
		config->meals_required = -1;
}

int	main(int ac, char **av)
{
	t_args	config;
	t_philo	*philo;

	if (validate_input(ac, av))
		return (-1);
	parse_arguments(&config, ac, av);
	philo = allocate_philosophers(&config);
	if (philo == NULL && free_philosopher_data(philo) == 0)
		return (-1);
	if (config.philo_count == 1)
	{
		print_status(philo, "has taken a fork");
		sleep_with_monitoring(config.time_to_die_ms, philo);
		print_status(philo, "died");
	}
	if (join_and_destroy(philo, config.philo_count) && free_philosopher_data(philo) == 0)
		return (-1);
	free_philosopher_data(philo);
	return (0);
}
