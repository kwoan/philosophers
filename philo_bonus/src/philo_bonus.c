/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwpark <kwpark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 18:25:01 by kwpark            #+#    #+#             */
/*   Updated: 2022/12/04 18:53:39 by kwpark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo_bonus.h"

int	main(int ac, char **av)
{
	t_args	args;

	if (check_args(ac, av))
		return (FAILURE);
	if (init(&args, ac, av))
		return (FAILURE);
	philo_process(&args);
	sem_close(args.print_sem);
	sem_close(args.forks);
	free_all(&args);
	return (0);
}