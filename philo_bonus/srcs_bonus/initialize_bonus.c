/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvine <cvine@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 12:27:02 by cvine             #+#    #+#             */
/*   Updated: 2022/04/10 19:56:47 by cvine            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	multi_sem_open(char *name, int count)
{
	sem_unlink(name);
	if (sem_open(name, O_CREAT | O_EXCL, 0666, count) == SEM_FAILED)
		exit(EXIT_FAILURE);
}

void	init_sem(int *param)
{
	multi_sem_open("/forks", param[num_of_philo]);
	multi_sem_open("/print", 1);
	multi_sem_open("/everyone_full", 0);
	multi_sem_open("/stop_simul", 0);
}

t_philo	*init_philo(int *param)
{
	t_philo	*philo;

	philo = malloc(sizeof(t_philo));
	if (!philo)
		exit(EXIT_FAILURE);
	philo->num_of_meals = 0;
	philo->last_meal_time = 0;
	philo->start_time = get_time();
	philo->param = param;
	init_sem(philo->param);
	return (philo);
}
