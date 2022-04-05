/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvine <cvine@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 17:36:29 by cvine             #+#    #+#             */
/*   Updated: 2022/04/05 18:00:50 by cvine            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print(t_philo *philo, t_lifecycle action, char *text)
{
	int	timestamp;

	timestamp = get_time() - philo->param->start_time;
	pthread_mutex_lock(&philo->param->print);
	if (action == take_forks)
	{
		printf(GREEN"%d %d %s\n"COLOR_RESET, timestamp, philo->id, text);
		printf(GREEN"%d %d %s\n"COLOR_RESET, timestamp, philo->id, text);
	}
	else if (action == eating)
		printf(YELLOW"%d %d %s\n"COLOR_RESET, timestamp, philo->id, text);
	else if (action == sleeping)
		printf(BLUE"%d %d %s\n"COLOR_RESET, timestamp, philo->id, text);
	else if (action == thinking)
		printf(MAGENTA"%d %d %s\n"COLOR_RESET, timestamp, philo->id, text);
	else
		printf(RED"%d %d %s\n"COLOR_RESET, timestamp, philo->id, text);
	pthread_mutex_unlock(&philo->param->print);
}