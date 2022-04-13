/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvine <cvine@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 19:52:41 by cvine             #+#    #+#             */
/*   Updated: 2022/04/13 20:07:06 by cvine            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	*meal_counter(void *tid)
{
	int		i;
	t_philo	*philo;

	i = 0;
	philo = ((t_philo *)tid);
	while (i++ < philo->param[num_of_philo])
		sem_wait(philo->meal);
	sem_wait(philo->print);
	sem_post(philo->stop);
	return (NULL);
}

void	*death_control(void *tid)
{
	int		i;
	t_philo	*philo;
	long	timestamp;

	i = 0;
	philo = ((t_philo *)tid);
	timestamp = get_time() - philo->start_time;
	while ((timestamp - philo->last_meal_time) <= philo->param[time_to_die])
		timestamp = get_time() - philo->start_time;
	print(philo, died);
	sem_post(philo->stop);
	return (NULL);
}

void	create_thread(t_philo *philo, pthread_t	*thread, void *routine(void *))
{
	if (pthread_create(thread, NULL, routine, (void *)philo))
		exit(EXIT_FAILURE);
	if (pthread_detach(*thread))
		exit(EXIT_FAILURE);
}