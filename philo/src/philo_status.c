/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_status.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwpark <kwpark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 02:47:52 by kwpark            #+#    #+#             */
/*   Updated: 2022/12/09 14:18:43 by kwpark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	set_forks(t_philo *ph)
{	
	// if (ph->philo_nbr % 2 == 1 && ph->philo_nbr != ph->arg->n_philos)
	// {
	// 	pthread_mutex_lock(ph->l_f);
	// 	pthread_mutex_lock(ph->r_f);
	// }
	// else
	// {
	// 	pthread_mutex_lock(ph->r_f);
	// 	pthread_mutex_lock(ph->l_f);
	// }
	pthread_mutex_lock(ph->l_f);
	pthread_mutex_lock(ph->r_f);
	// if (!ph->stop && !ph->arg->dead)
	// {
		print_out(ph, "has taken a fork");
		print_out(ph, "has taken a fork");
	// }
}

void	eating(t_philo *ph)
{	
	// if ((!ph->arg->dead && !ph->stop))
	ph->n_eat++;
	ph->time = print_out(ph, "is eating");
	ft_usleep(ph->time, ph->arg->t_eat);
	pthread_mutex_unlock(ph->l_f);
	pthread_mutex_unlock(ph->r_f);
}

void	sleeping(t_philo *ph)
{
	long time;
	// if ((!ph->arg->dead && !ph->stop))
	time = print_out(ph, "is sleeping");
	ft_usleep(time, ph->arg->t_sleep);
}

void	thinking(t_philo *ph)
{
	// if ((!ph->arg->dead && !ph->stop))
		print_out(ph, "is thinking");
}
