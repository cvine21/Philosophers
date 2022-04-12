/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvine <cvine@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 17:36:29 by cvine             #+#    #+#             */
/*   Updated: 2022/04/12 20:53:14 by cvine            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print(int timestamp, t_philo *philo, t_lifecycle action)
{
	pthread_mutex_lock(&philo->param->print);
	if (philo->param->death_flag
		|| philo->num_of_meals == philo->param->each_philo_must_eat)
	{
		pthread_mutex_unlock(&philo->param->print);
		return ;
	}
	else if (action == take_forkss)
	{
		printf(GREEN"%d %d has taken a fork\n"DISCOLOR, timestamp, philo->id);
		printf(GREEN"%d %d has taken a fork\n"DISCOLOR, timestamp, philo->id);
	}
	else if (action == eating)
		printf(YELLOW"%d %d is eating\n"DISCOLOR, timestamp, philo->id);
	else if (action == sleeping)
		printf(BLUE"%d %d is sleeping\n"DISCOLOR, timestamp, philo->id);
	else if (action == thinking)
		printf(MAGENTA"%d %d is thinking\n"DISCOLOR, timestamp, philo->id);
	else if (action == died)
	{
		printf(RED"%d %d died\n"DISCOLOR, timestamp, philo->id);
		philo->param->death_flag = 1;
	}
	pthread_mutex_unlock(&philo->param->print);
}
