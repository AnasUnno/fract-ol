/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: araji-af <araji-af@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 09:48:48 by araji-af          #+#    #+#             */
/*   Updated: 2023/04/07 00:21:50 by araji-af         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	wich_frac(t_data *data, char *av)
{
	if (!ft_strcmp(av, "mandelbrot"))
		data->identity = 1;
	else if (!ft_strcmp(av, "julia"))
		data->identity = 2;
	else
	{
		ft_putstr_fd("please pick one of these : mandelbrot, julia.\n", 1);
		exit (1);
	}
}

int	julia_changer(int x, int y, t_data *data)
{
	if (data->lock > 0)
	{
		if (x > 0 && x <= SIZE && y > 0 && y <= SIZE)
		{
			data->diff_x = resize_coord(x, data->start_x, data->end_x);
			data->diff_y = resize_coord(y, data->start_y, data->end_y);
			draw(data);
		}
	}
	return (0);
}
