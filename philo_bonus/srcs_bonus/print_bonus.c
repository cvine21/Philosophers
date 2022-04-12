/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvine <cvine@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 17:36:29 by cvine             #+#    #+#             */
/*   Updated: 2022/04/11 17:36:12 by cvine            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	print(int timestamp, t_philo *philo, t_lifecycle action)
{
	sem_wait(philo->print);
	if (action == take_forks)
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
		printf(RED"%d %d died\n"COLOR_RESET, timestamp, philo->id);
	if (action != died)
		sem_post(philo->print);
}
