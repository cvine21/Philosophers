/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_philos.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvine <cvine@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 13:54:25 by cvine             #+#    #+#             */
/*   Updated: 2022/03/20 18:24:58 by cvine            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*routine(void *tid)
{
	t_philo	*philo;

	philo = ((t_philo *)tid);
	return (NULL);
}

int	create_philos(int num_of_philos, t_philo *philo)
{
	int			i;
	pthread_t	*philo_thread;

	i = -1;
	philo_thread = malloc(sizeof(pthread_t) * num_of_philos);
	if (!philo_thread)
		return (1);
	while (++i < num_of_philos)
		pthread_create(&philo_thread[i], NULL, &routine, (void *)philo);
	i = -1;
	while (++i < num_of_philos)
		pthread_join(philo_thread[i], NULL);
	return (0);
}
