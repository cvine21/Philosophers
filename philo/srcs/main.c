/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvine <cvine@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 18:55:32 by cvine             #+#    #+#             */
/*   Updated: 2022/03/21 21:03:58 by cvine            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// int mails = 0;
// pthread_mutex_t mutex;


// void* routine()
// { 
// 	for (int i = 0; i < 1000000; i++)
// 	{
// 		pthread_mutex_lock(&mutex);
// 			mails++;
// 		pthread_mutex_unlock(&mutex);
// 	}
// }


// int main(int argc, char* argv[])
// {
// 	pthread_t t1, t2;
// 	pthread_mutex_init(&mutex, NULL);
// 	if (pthread_create(&t1, NULL, &routine, NULL))
// 	{
// 		return (EXIT_FAILURE);
// 	}
// 	if (pthread_create(&t2, NULL, &routine, NULL))
// 	{
// 		return (2);
// 	}
// 	if (pthread_join(t1, NULL))
// 	{
// 		return (3);
// 	}
// 	if (pthread_join(t2  , NULL))
// 	{
// 		return (4);
// 	}
// 	pthread_mutex_destroy(&mutex);
// 	printf("Number of mails: %d", mails);
// 	return (EXIT_SUCCESS);
// }

int main(int argc, char **argv)
{
	int		*int_argv;
	t_param	*param;

	int_argv = parse(argc, argv);
	if (!int_argv)
		return (EXIT_FAILURE);
	param = init_struct_param(argc, int_argv);
	if (!param)
		return (EXIT_FAILURE);
	if (!create_philo_threads(param->num_of_philos, param->philo))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
