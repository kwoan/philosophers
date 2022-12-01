/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_status.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwpark <kwpark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 02:47:52 by kwpark            #+#    #+#             */
/*   Updated: 2022/12/02 06:36:18 by kwpark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	set_forks(t_philo *ph)
{	
	if (ph->philo_nbr % 2 == 1 && ph->philo_nbr != ph->arg->n_philos)
	{
		pthread_mutex_lock(ph->l_f);
		pthread_mutex_lock(ph->r_f);
	}
	else
	{
		pthread_mutex_lock(ph->r_f);
		pthread_mutex_lock(ph->l_f);
	}
	if (!ph->stop)
	{
		pthread_mutex_lock(&ph->arg->print_mutex);
		printf("%ld %d has taken a fork\n", \
			get_time() - ph->arg->time, ph->philo_nbr);
		printf("%ld %d has taken a fork\n", \
			get_time() - ph->arg->time, ph->philo_nbr);
		pthread_mutex_unlock(&ph->arg->print_mutex);
	}
}

void	eating(t_philo *ph)
{	
	pthread_mutex_lock(&ph->arg->print_mutex);
	printf("%ld %d is eating\n", \
		get_time() - ph->arg->time, ph->philo_nbr);
	pthread_mutex_unlock(&ph->arg->print_mutex);
	ph->n_eat++;
	ph->time = get_time();
	ft_usleep(ph->arg->t_eat);
	pthread_mutex_unlock(ph->r_f);
	pthread_mutex_unlock(ph->l_f);
}

void	sleeping(t_philo *ph)
{
	pthread_mutex_lock(&ph->arg->print_mutex);
	printf("%ld %d is sleeping\n", \
		get_time() - ph->arg->time, ph->philo_nbr);
	pthread_mutex_unlock(&ph->arg->print_mutex);
	ft_usleep(ph->arg->t_sleep);
}

void	thinking(t_philo *ph)
{
	pthread_mutex_lock(&ph->arg->print_mutex);
	printf("%ld %d is thinking\n", \
		get_time() - ph->arg->time, ph->philo_nbr);
	pthread_mutex_unlock(&ph->arg->print_mutex);
}
