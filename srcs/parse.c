/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvine <cvine@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 19:52:20 by cvine             #+#    #+#             */
/*   Updated: 2022/03/16 19:58:17 by cvine            ###   ########.fr       */
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

int is_valid_argv(int index, int intArgv)
{
	if (index == 0 && intArgv < 2)
		printf("Error\nThere must be at least 2 philosophers\n");
	else if (index > 0 && index < 4 && intArgv < 0)
		printf("Error\nThe time value cannot be negative\n");
	else if (index == 4 && intArgv < 0)
		printf("Error\nEach philosopher must eat times cannot be negative\n");
	else
		return (0);
	return (1);
}

int	*cast_argv_to_int(int argc, char **argv)
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
		if (is_valid_argv(i, intArgv[i]))
			return (NULL);
		argv++;
		i++;
	}
	return (intArgv);
}
