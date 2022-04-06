/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvine <cvine@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 18:55:32 by cvine             #+#    #+#             */
/*   Updated: 2022/04/06 16:54:24 by cvine            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	int		*int_argv;
	t_philo	*philo;

	int_argv = parse(argc, argv);
	if (!int_argv)
		return (EXIT_FAILURE);
	philo = initialize(argc, int_argv);
	if (!philo)
		return (EXIT_FAILURE);
	if (create_threads(philo, philo->param->num_of_philos))
		return (EXIT_FAILURE);
	printf(RED"Simulation stopped\n"COLOR_RESET);
	return (EXIT_SUCCESS);
}
