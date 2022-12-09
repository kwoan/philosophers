/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_status.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwpark <kwpark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 02:47:52 by kwpark            #+#    #+#             */
/*   Updated: 2022/12/09 15:41:04 by kwpark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	set_forks(t_philo *ph)
{	
	pthread_mutex_lock(ph->l_f);
	pthread_mutex_lock(ph->r_f);
	print_out(ph, "has taken a fork");
	print_out(ph, "has taken a fork");
	if ((ph->arg->dead || ph->stop))
	{
		pthread_mutex_unlock(ph->l_f);
		pthread_mutex_unlock(ph->r_f);
	}
}

void	eating(t_philo *ph)
{	
	ph->n_eat++;
	ph->time = print_out(ph, "is eating");
	ft_usleep(ph->time, ph->arg->t_eat);
	pthread_mutex_unlock(ph->l_f);
	pthread_mutex_unlock(ph->r_f);
}

void	sleeping(t_philo *ph)
{
	long	time;

	time = print_out(ph, "is sleeping");
	ft_usleep(time, ph->arg->t_sleep);
}

void	thinking(t_philo *ph)
{
	print_out(ph, "is thinking");
}
