/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: araji-af <araji-af@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 14:55:21 by araji-af          #+#    #+#             */
/*   Updated: 2023/03/26 03:35:42 by araji-af         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	main(int ac, char **av)
{
	t_data	data;

	(void)av;
	if (ac > 1)
		ft_putstr_fd("No argument is required \n", 1);
	first_to_call(&data);
}
