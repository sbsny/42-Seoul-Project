/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonyun <seonyun@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 05:30:28 by seonyun           #+#    #+#             */
/*   Updated: 2022/09/09 05:30:47 by seonyun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <unistd.h>

int	ft_putnbr(unsigned int a)
{
	if (a > 9)
		ft_putnbr(a / 10);
	write(1, &"0123456789"[a % 10], 1);
	return (0);
}

void	signal_handling(int signum)
{
	static int	i;
	static char	c;

	if (i < 8)
	{
		c = c << 1;
		if (signum == SIGUSR2)
			c += 1;
		i++;
	}
	if (i >= 8)
	{
		write(1, &c, 1);
		c = 0;
		i = 0;
	}
}

int	main(void)
{
	write(1, "PID : ", 6);
	ft_putnbr(getpid());
	write(1, "\n", 1);
	signal(SIGUSR1, &signal_handling);
	signal(SIGUSR2, &signal_handling);
	while (1)
		pause();
	return (0);
}
