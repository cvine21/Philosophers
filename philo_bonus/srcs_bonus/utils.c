/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvine <cvine@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 11:50:50 by cvine             #+#    #+#             */
/*   Updated: 2022/04/14 12:52:20 by cvine            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

long	current_time(void)
{
	struct timeval	current_time;
	long			millisec_time;

	gettimeofday(&current_time, NULL);
	millisec_time = current_time.tv_sec * 1000 + current_time.tv_usec / 1000;
	return (millisec_time);
}

void	ft_usleep(long millisec)
{
	long	sleep_start_time;

	sleep_start_time = current_time();
	while (current_time() - sleep_start_time < millisec)
		usleep(300);
}

void	terminate(t_philo *philo, int *param, pid_t *pid)
{
	int	i;

	i = 0;
	sem_close(philo->forks);
	sem_close(philo->print);
	sem_close(philo->stop);
	free(param);
	free(philo);
	while (i < philo->param[num_of_philo])
		kill(pid[i++], SIGKILL);
	free(pid);
}

int	ft_isnumber(char *str)
{
	if (!str)
		return (1);
	if (*str == '-')
		str++;
	while (*str)
	{
		if (*str < 48 || *str > 57)
			return (1);
		str++;
	}
	return (0);
}

int	ft_atoi(const char *str)
{
	long int	rep;
	int			minus;

	rep = 0;
	minus = 1;
	while ((9 <= *str && *str <= 13) || *str == 32)
		str++;
	if (*str == '-')
		minus = -1;
	if (*str == '-' || *str == '+')
		str++;
	while (48 <= *str && *str <= 57)
	{
		rep = rep * 10 + (*str - 48);
		if (rep < 0)
		{
			if (1 == minus)
				return (-1);
			else
				return (0);
		}
		str++;
	}
	return (rep * minus);
}
