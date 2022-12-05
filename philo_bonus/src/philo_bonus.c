/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwpark <kwpark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 18:25:01 by kwpark            #+#    #+#             */
/*   Updated: 2022/12/05 22:53:55 by kwpark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo_bonus.h"

int	main(int ac, char **av)
{
	t_args	args;
	int		*pids;

	if (check_args(ac, av))
		return (FAILURE);
	if (init(&args, ac, av))
		return (FAILURE);
	pids = philo_process(&args);
	sem_close(args.print_sem);
	sem_close(args.forks);
	ft_exit(&args, pids, 0);
}
