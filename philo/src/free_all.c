/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwpark <kwpark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 04:03:51 by kwpark            #+#    #+#             */
/*   Updated: 2022/12/02 05:17:53 by kwpark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	all_mutex_destroy(t_args *args)
{
	int	i;

	i = 0;
	while (i < args->n_philos)
	{
		pthread_mutex_unlock(&args->forks[i]);
		pthread_mutex_destroy(&args->forks[i]);
		i++;
	}
	pthread_mutex_unlock(&args->print_mutex);
	pthread_mutex_destroy(&args->print_mutex);
}

void	free_all(t_args *args)
{
	free(args->philos);
	free(args->forks);
}
