/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_threads.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvine <cvine@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 13:54:25 by cvine             #+#    #+#             */
/*   Updated: 2022/04/07 13:20:46 by cvine            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	create_philo_threads(t_philo *philo, int num_of_philos, pthread_t *waiter)
{
	int			i;
	pthread_t	*philo_thread;

	i = -1;
	philo_thread = malloc(sizeof(pthread_t) * num_of_philos);
	if (!philo_thread)
		return (EXIT_FAILURE);
	while (++i < num_of_philos)
		if (pthread_create(
				&philo_thread[i], NULL, &simulation, (void *)(philo + i)))
			return (EXIT_FAILURE);
	if (pthread_join(*waiter, NULL))
		return (EXIT_FAILURE);
	while (i--)
	{
		if (pthread_join(philo_thread[i], NULL))
			return (EXIT_FAILURE);
	}
	free(philo_thread);
	return (EXIT_SUCCESS);
}

int	create_threads(t_philo *philo, int num_of_philos)
{
	int			i;
	pthread_t	waiter;

	i = 0;
	if (pthread_create(&waiter, NULL, &waiter_control, (void *)philo))
		return (EXIT_FAILURE);
	if (create_philo_threads(philo, philo->param->num_of_philos, &waiter))
		return (EXIT_FAILURE);
	while (i++ < num_of_philos)
		pthread_mutex_destroy(philo->left_fork);
	while (i--)
		pthread_mutex_destroy(philo->right_fork);
	pthread_mutex_destroy(&philo->param->print);
	return (EXIT_SUCCESS);
}
