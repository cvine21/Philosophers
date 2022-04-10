/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvine <cvine@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 11:50:50 by cvine             #+#    #+#             */
/*   Updated: 2022/04/10 18:15:20 by cvine            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

long	get_time(void)
{
	struct timeval	current_time;
	long			millisec_time;

	gettimeofday(&current_time, NULL);
	millisec_time = current_time.tv_sec * 1000 + current_time.tv_usec / 1000;
	return (millisec_time);
}

void	ft_usleep(long millisec)
{
	long	current_time;

	current_time = get_time();
	while (get_time() - current_time < millisec)
		usleep(300);
}

void	terminate(t_philo *philo, int *param, pid_t *pid)
{
	int i;

	i = 0;
	free(param);
	free(philo);
	sem_close(philo->forks);
	sem_close(philo->print);
	sem_close(philo->everyone_full);
	sem_close(philo->stop_simul);
	while (i < philo->param[num_of_philo])
		kill(pid[i++], SIGTERM);
}
