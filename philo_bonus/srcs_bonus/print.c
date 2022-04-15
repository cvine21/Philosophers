/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvine <cvine@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 17:36:29 by cvine             #+#    #+#             */
/*   Updated: 2022/04/14 20:22:12 by cvine            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	print(t_philo *philo, t_lifecycle action)
{
	long	timestamp;

	sem_wait(philo->print);
	timestamp = current_time() - philo->start_time;
	if (action == take_forks)
	{
		printf(GREEN"%ld %d has taken a fork\n"DISCOLOR, timestamp, philo->id);
		printf(GREEN"%ld %d has taken a fork\n"DISCOLOR, timestamp, philo->id);
	}
	else if (action == eating)
		printf(YELLOW"%ld %d is eating\n"DISCOLOR, timestamp, philo->id);
	else if (action == sleeping)
		printf(BLUE"%ld %d is sleeping\n"DISCOLOR, timestamp, philo->id);
	else if (action == thinking)
		printf(MAGENTA"%ld %d is thinking\n"DISCOLOR, timestamp, philo->id);
	else if (action == died)
		printf(RED"%ld %d died\n"DISCOLOR, timestamp, philo->id);
	if (action != died)
		sem_post(philo->print);
}
