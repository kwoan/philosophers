/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwpark <kwpark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 00:04:32 by kwpark            #+#    #+#             */
/*   Updated: 2022/12/04 18:57:16 by kwpark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo_bonus.h"

static t_bool	ft_isdigit(char *str)
{
	while (*str)
	{
		if (!(*str >= '0' && *str <= '9'))
			return (FAILURE);
		str++;
	}
	return (SUCCESS);
}

t_bool	check_args(int ac, char **av)
{
	int	i;

	i = 1;
	if (ac < 5 || ac > 6)
	{
		printf("arguments must be 4 or 5\n");
		return (FAILURE);
	}
	while (i < ac)
	{
		if (ft_isdigit(av[i]) || !ft_atoi(av[i]))
		{
			printf("invalid argument\n");
			return (FAILURE);
		}
		i++;
	}
	return (SUCCESS);
}
