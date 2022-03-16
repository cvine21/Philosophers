/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvine <cvine@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 12:27:02 by cvine             #+#    #+#             */
/*   Updated: 2022/03/16 16:40:27 by cvine            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_arg *init_args(int argc, char **argv)
{
	t_arg	*param;
	int		*intArgv;

	intArgv = cast_argv_to_int(argc, argv + 1);
	if (!intArgv)
		return (NULL);

	param = malloc(sizeof(t_arg));
	if (!param)
		return (NULL);

	param->philosophers_num = intArgv[0];
	param->die_time = intArgv[1];
	param->eat_time = intArgv[2];
	param->sleep_time = intArgv[3];
	if (argc == 6)
		param->each_philo_must_eat_times = intArgv[4];
	return (param);
}

