/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwpark <kwpark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 00:20:08 by kwpark            #+#    #+#             */
/*   Updated: 2022/11/29 21:37:22 by kwpark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

int	main(int ac, char **av)
{
	t_args	args;

	if (check_args(ac, av))
		return (FAILURE);
	if (init(&args, ac, av))
		return (FAILURE);
	philo_thread(&args);
	return (0);
}
