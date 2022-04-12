/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvine <cvine@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 12:27:02 by cvine             #+#    #+#             */
/*   Updated: 2022/04/12 15:23:12 by cvine            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

sem_t	*multi_sem_open(const char *name, int count)
{
	sem_t *sem;
	
	sem_unlink(name);
	sem = sem_open(name, O_CREAT | O_EXCL, 0666, count);
	if (sem == SEM_FAILED)
		exit(EXIT_FAILURE);
	return (sem);
}

void	init_sem(int *param, t_philo *philo)
{
	philo->forks = multi_sem_open("/forks", param[num_of_philo]);
	philo->print = multi_sem_open("/print", 1);
	philo->everyone_full = multi_sem_open("/everyone_full", 0);
	philo->stop = multi_sem_open("/stop", 0);
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
	init_sem(philo->param, philo);
	return (philo);
}
