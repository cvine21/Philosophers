/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_death_thread_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvine <cvine@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 13:54:25 by cvine             #+#    #+#             */
/*   Updated: 2022/04/13 19:51:01 by cvine            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	create_processes(t_philo *philo, int *param)
{
	int			i;
	pid_t		*pid;
	pthread_t	meal;

	i = 0;
	create_thread(philo, &meal, meal_counter);
	pid = malloc(sizeof(pid_t) * param[num_of_philo]);
	if (!pid)
		return (EXIT_FAILURE);
	while (i < param[num_of_philo])
	{
		pid[i] = fork();
		if (pid[i] == -1)
			return (EXIT_FAILURE);
		else if (!pid[i])
			simulation(philo, i + 1);
		i++;
	}
	sem_wait(philo->stop);
	terminate(philo, param, pid);
	return (EXIT_SUCCESS);
}
