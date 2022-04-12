/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_threads_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvine <cvine@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 13:54:25 by cvine             #+#    #+#             */
/*   Updated: 2022/04/12 15:11:02 by cvine            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

// void	*meal_control(void *tid)
// {
// 	t_philo	*philo;

// 	philo = ((t_philo *)tid);
// 	while (1)
// 	{
// 		if (philo->num_of_meals == )
// 	}
// 	return (NULL);
// }

int	create_philo_processes(int *param)
{
	int		i;
	pid_t	*pid;
	t_philo	*philo;

	i = 0;
	philo = init_philo(param);
	pid = malloc(sizeof(pid_t) * param[num_of_philo]);
	if (!pid)
		return (EXIT_FAILURE);
	while(i < param[num_of_philo])
	{
		pid[i] = fork();
		if (pid[i] == -1)
			return (EXIT_FAILURE);
		else if (!pid[i])
		{
			simulation(philo, i + 1);
			return(EXIT_SUCCESS);
		}
		i++;
	}
	sem_wait(philo->stop);
	terminate(philo, param, pid);
	return (EXIT_SUCCESS);
}