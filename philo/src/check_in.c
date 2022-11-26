/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_in.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwpark <kwpark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 00:04:32 by kwpark            #+#    #+#             */
/*   Updated: 2022/11/27 00:26:48 by kwpark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long    get_time(void)
{
	struct timeval  tv;
	long            ret;

	gettimeofday(&tv, NULL);
	ret = tv.tv_sec * 1000 + tv.tv_usec / 1000;
	return (ret);
}

static int		ft_atoi(const char *str)
{
	int	ret;
	int	sign;

	ret = 0;
	sign = 1;
	while (*str == ' ')
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		ret = ret * 10 + (*str - '0');
		str++;
	}
	return (ret * sign);
}

static t_bool	ft_isdigit(char *str)
{
	while (*str)
	{
		if (!(*str >= '0' && *str <= '9'))
			return (FALSE);
	}
	return (TRUE);
}

t_bool	check_in(int ac, char **av)
{
	int	i;

	i = 1;
	if (ac > 5 || ac < 6)
		return (FALSE);
	while (i < ac)
	{
		if (!ft_isdigit(av[i]) || (ft_atoi(av[i]) <= 0))
			return (FALSE);
		i++;
	}
	return (TRUE);
}
