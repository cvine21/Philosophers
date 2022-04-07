/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvine <cvine@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 18:55:32 by cvine             #+#    #+#             */
/*   Updated: 2022/04/07 15:57:41 by cvine            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	main(int argc, char **argv)
{
	int		*int_argv;

	int_argv = parse(argc, argv);
	if (!int_argv)
		return (EXIT_FAILURE);
	if (!initialize(argc, int_argv))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
