/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvine <cvine@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 19:52:20 by cvine             #+#    #+#             */
/*   Updated: 2022/03/13 19:24:50 by cvine            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int check_if_number(char **argv)
{
	int	i;

	i = 0;
	while (argv[++i])
	{
		if (ft_isnumber(argv[i]))
		{
			printf("Error\nThe argument \"%s\" is not a number\n", argv[i]);
			return (1);
		}
	}
	return (0);
}

int	*get_int_argv(int argc, char **argv)
{
	int i;
	int *intArgv;

	i = 0;
	if (check_if_number(argv))
		return (NULL);
	intArgv = malloc(sizeof(int) * (argc - 1));
	if (!intArgv)
		return (NULL);
	while (*argv)
	{
		intArgv[i] = ft_atoi(*argv);
		argv++;
		i++;
	}
	return (intArgv);
}
