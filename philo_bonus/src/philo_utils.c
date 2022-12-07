/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwpark <kwpark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 03:29:28 by kwpark            #+#    #+#             */
/*   Updated: 2022/12/07 16:19:27 by kwpark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo_bonus.h"

long	get_time(void)
{
	struct timeval	tv;
	long			ret;

	gettimeofday(&tv, NULL);
	ret = tv.tv_sec * 1000 + tv.tv_usec / 1000;
	return (ret);
}

void	ft_usleep(int time)
{
	long	curr;

	curr = get_time();
	while (get_time() - curr < (long)time)
		usleep(50);
}

int	ft_atoi(const char *str)
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

int	check_n_eat(t_philo *ph)
{
	int	ret;

	sem_wait(ph->arg->n_eat_sem);
	ret = (ph->n_eat >= ph->arg->num_to_eat);
	sem_post(ph->arg->n_eat_sem);
	return (ret);
}
