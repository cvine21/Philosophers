/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvine <cvine@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 18:27:40 by cvine             #+#    #+#             */
/*   Updated: 2022/04/05 17:54:20 by cvine            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	death_check(t_philo *philo, int timestamp)
{
	if ((timestamp - philo->last_meal_time) > philo->param->time_to_die
		&& philo->state != eating)
		philo->param->death_flag = 1;
}

void	action(t_philo *philo, t_lifecycle action)
{
	int	timestamp;

	timestamp = get_time() - philo->param->start_time;
	philo->state = action;
	if (action == take_forks)
		print(philo, action, "has taken a fork");
	else if (action == eating)
	{
		philo->last_meal_time = get_time() - philo->param->start_time;
		print(philo, action, "is eating");
		ft_usleep(philo->param->time_to_eat);
		philo->num_of_meals++;
	}
	else if (action == sleeping)
	{
		print(philo, action, "is sleeping");
		ft_usleep(philo->param->time_to_sleep);
	}
	else
		print(philo, action, "is thinking");
	death_check(philo, timestamp);
}
