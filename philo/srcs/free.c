/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvine <cvine@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 11:50:50 by cvine             #+#    #+#             */
/*   Updated: 2022/04/07 13:22:30 by cvine            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*free_mem(t_philo *philo, t_param *param, pthread_mutex_t *fork,
			int *int_argv)
{
	free(int_argv);
	free(param);
	free(fork);
	free(philo);
	return (NULL);
}
