/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_philos.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvine <cvine@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 13:54:25 by cvine             #+#    #+#             */
/*   Updated: 2022/03/19 18:16:51 by cvine            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int create_philos(int num_of_philos)
{
	int	i;
	pthread_t *philo_thread;

	i = -1;
	philo_thread = malloc(sizeof(pthread_t) * num_of_philos);
	if (!philo_thread)
		return (1);
	while (++i < num_of_philos)
		pthread_create(philo_thread[i], NULL, &routine, NULL);

	i = -1;
	while (++i < num_of_philos)
		pthread_join(philo_thread[i], NULL);
	while
}