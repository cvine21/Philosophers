/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvine <cvine@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 19:52:41 by cvine             #+#    #+#             */
/*   Updated: 2022/04/14 12:48:10 by cvine            ###   ########.fr       */
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

void	create_waiter_thread(t_philo *philo)
{
	pthread_t	death;

	if (pthread_create(&death, NULL, &waiter_routine, (void *)philo))
		exit(EXIT_FAILURE);
	if (pthread_detach(death))
		exit(EXIT_FAILURE);
}
