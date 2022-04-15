/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   waiter.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvine <cvine@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 19:52:41 by cvine             #+#    #+#             */
/*   Updated: 2022/04/15 14:11:19 by cvine            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	*waiter_routine(void *tid)
{
	int		i;
	t_philo	*philo;

	i = 0;
	philo = ((t_philo *)tid);
	while (current_time() - philo->last_meal_time <= philo->param[time_to_die])
	{
	}
	print(philo, died);
	while (i++ < philo->param[num_of_philo])
		sem_post(philo->stop);
	return (NULL);
}

void	create_waiter(t_philo *philo)
{
	int			i;
	pthread_t	death;

	i = 0;
	if (pthread_create(&death, NULL, &waiter_routine, (void *)philo))
	{
		while (i++ < philo->param[num_of_philo])
			sem_post(philo->stop);
		exit(EXIT_FAILURE);
	}
	if (pthread_detach(death))
	{
		while (i++ < philo->param[num_of_philo])
			sem_post(philo->stop);
		exit(EXIT_FAILURE);
	}
}
