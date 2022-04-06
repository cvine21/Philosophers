/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvine <cvine@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 17:36:29 by cvine             #+#    #+#             */
/*   Updated: 2022/04/06 16:19:41 by cvine            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print(int timestamp, t_philo *philo, t_lifecycle action)
{
	pthread_mutex_lock(&philo->param->print);
	if (philo->param->death_flag)
	{
		pthread_mutex_unlock(&philo->param->print);
		return ;
	}
	else if (action == take_forks)
	{
		printf(GREEN"%d %d has taken a fork\n"COLOR_RESET, timestamp, philo->id);
		printf(GREEN"%d %d has taken a fork\n"COLOR_RESET, timestamp, philo->id);
	}
	else if (action == eating)
		printf(YELLOW"%d %d is eating\n"COLOR_RESET, timestamp, philo->id);
	else if (action == sleeping)
		printf(BLUE"%d %d is sleeping\n"COLOR_RESET, timestamp, philo->id);
	else if (action == thinking)
		printf(MAGENTA"%d %d is thinking\n"COLOR_RESET, timestamp, philo->id);
	else if (action == died)
	{
		printf(RED"%d %d died\n"COLOR_RESET, timestamp, philo->id);
		philo->param->death_flag = 1;
	}
	pthread_mutex_unlock(&philo->param->print);
}
