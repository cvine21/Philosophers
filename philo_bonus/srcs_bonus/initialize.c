/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvine <cvine@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 12:27:02 by cvine             #+#    #+#             */
/*   Updated: 2022/04/14 12:47:10 by cvine            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

sem_t	*init_sem(const char *name, int count)
{
	sem_t	*sem;

	sem_unlink(name);
	sem = sem_open(name, O_CREAT | O_EXCL, 0666, count);
	if (sem == SEM_FAILED)
		exit(EXIT_FAILURE);
	return (sem);
}

t_philo	*init_philo(int *param)
{
	t_philo	*philo;

	philo = malloc(sizeof(t_philo));
	if (!philo)
		exit(EXIT_FAILURE);
	philo->num_of_meals = 0;
	philo->last_meal_time = current_time();
	philo->start_time = current_time();
	philo->param = param;
	philo->forks = init_sem("/forks", param[num_of_philo]);
	philo->print = init_sem("/print", 1);
	philo->stop = init_sem("/stop", 0);
	return (philo);
}
