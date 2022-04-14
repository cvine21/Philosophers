/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_process.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvine <cvine@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 12:38:41 by cvine             #+#    #+#             */
/*   Updated: 2022/04/14 12:38:43 by cvine            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	create_processes(t_philo *philo, int *param)
{
	int			i;
	pid_t		*pid;

	i = 0;
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
	i = 0;
	while (i++ < param[num_of_philo])
		sem_wait(philo->stop);
	terminate(philo, param, pid);
	return (EXIT_SUCCESS);
}
