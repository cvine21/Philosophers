/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvine <cvine@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 18:55:32 by cvine             #+#    #+#             */
/*   Updated: 2022/03/13 19:35:37 by cvine            ###   ########.fr       */
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
// 		return (1);
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
// 	return (0);
// }

int main(int argc, char **argv)
{
	(void) argc;
	int i;
	int *args;

	i = -1;
	if (argc < 5 | argc > 6)
	{
		printf("Invalid number of arguments, must be 5 or 6(optional).\n");
		return (0);
	}
	args = get_int_argv(argc, argv + 1);
	if (!argc)
		return (1);
	return (0);
}