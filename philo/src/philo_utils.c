/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwpark <kwpark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 03:29:28 by kwpark            #+#    #+#             */
/*   Updated: 2022/12/07 16:18:01 by kwpark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

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

int	check_n_eat(t_philo *ph, int i)
{
	int	ret;

	pthread_mutex_lock(&ph->arg->n_eat_mutex);
	ret = (ph->arg->philos[i].n_eat < ph->arg->num_to_eat);
	pthread_mutex_unlock(&ph->arg->n_eat_mutex);
	return (ret);
}

int	check_dead_stop(t_philo *ph)
{
	int	ret;

	pthread_mutex_lock(&ph->arg->dead_mutex);
	pthread_mutex_lock(&ph->arg->stop_mutex);
	ret = (ph->arg->dead || ph->stop);
	pthread_mutex_unlock(&ph->arg->stop_mutex);
	pthread_mutex_unlock(&ph->arg->dead_mutex);
	return (ret);
}
