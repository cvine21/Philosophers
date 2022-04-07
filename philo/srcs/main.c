/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvine <cvine@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 18:55:32 by cvine             #+#    #+#             */
/*   Updated: 2022/04/07 13:14:59 by cvine            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	
	int		*int_argv;

	int_argv = parse(argc, argv);
	if (!int_argv)
		return (EXIT_FAILURE);
	if (!initialize(argc, int_argv))
		return (EXIT_FAILURE);
	// if (!philo)
	// 	return (free_mem(philo, param, NULL, int_argv));
	// printf(RED"Simulation started\n"COLOR_RESET);
	// if (create_threads(philo, philo->param->num_of_philos))
	// 	return (EXIT_FAILURE);
	// printf(RED"Simulation stopped"COLOR_RESET);
	return (EXIT_SUCCESS);
}
