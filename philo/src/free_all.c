/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwpark <kwpark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 04:03:51 by kwpark            #+#    #+#             */
/*   Updated: 2022/12/09 15:45:58 by kwpark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	all_mutex_destroy(t_args *args)
{
	int	i;

	i = 0;
	while (i < args->n_philos)
	{
		pthread_mutex_destroy(&args->forks[i]);
		i++;
	}
	pthread_mutex_destroy(&args->print_mutex);
	pthread_mutex_destroy(&args->dead_mutex);
}

void	free_all(t_args *args)
{
	free(args->philos);
	free(args->forks);
}
