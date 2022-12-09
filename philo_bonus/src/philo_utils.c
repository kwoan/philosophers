/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwpark <kwpark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 03:29:28 by kwpark            #+#    #+#             */
/*   Updated: 2022/12/09 16:10:27 by kwpark           ###   ########.fr       */
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

void	ft_usleep(long start, int time)
{
	usleep(time * 800);
	while (get_time() - start < (long)time)
		usleep(300);
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

long	print_out(t_philo *ph, char *s)
{
	long	time;

	sem_wait(ph->arg->print_sem);
	time = get_time();
	printf("%ld %d %s\n", \
		time - ph->arg->time, ph->philo_nbr, s);
	sem_post(ph->arg->print_sem);
	return (time);
}
