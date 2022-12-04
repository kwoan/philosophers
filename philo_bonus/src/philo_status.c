/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_status.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwpark <kwpark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 18:39:09 by kwpark            #+#    #+#             */
/*   Updated: 2022/12/04 18:45:18 by kwpark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo_bonus.h"

void    set_forks(t_philo *ph)
{
    sem_wait(ph->arg->forks);
    sem_wait(ph->arg->forks);
    sem_wait(ph->arg->print_sem);
    printf("%ld %d has taken a fork\n", \
        get_time() - ph->arg->time, ph->philo_nbr);
    printf("%ld %d has taken a fork\n", \
        get_time() - ph->arg->time, ph->philo_nbr);
    sem_post(ph->arg->print_sem);
}

void    eating(t_philo *ph)
{
    sem_wait(ph->arg->print_sem);
    printf("%ld %d is eating\n", \
        get_time() - ph->arg->time, ph->philo_nbr);
    sem_post(ph->arg->print_sem);
    ph->n_eat++;
    ph->time = get_time();
    ft_usleep(ph->arg->t_eat);
    sem_post(ph->arg->forks);
    sem_post(ph->arg->forks);
}

void    sleeping(t_philo *ph)
{
    sem_wait(ph->arg->print_sem);
    printf("%ld %d is sleeping\n", \
        get_time() - ph->arg->time, ph->philo_nbr);
    sem_post(ph->arg->print_sem);
    ft_usleep(ph->arg->t_sleep);
}

void    thinking(t_philo *ph)
{
    sem_wait(ph->arg->print_sem);
    printf("%ld %d is thinking\n", \
        get_time() - ph->arg->time, ph->philo_nbr);
    sem_post(ph->arg->print_sem);
}
