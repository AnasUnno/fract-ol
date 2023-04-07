/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: araji-af <araji-af@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 17:30:07 by araji-af          #+#    #+#             */
/*   Updated: 2023/04/05 16:36:27 by araji-af         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	mandelbrot(t_data *data, double x1, double y1)
{
	double	x;
	double	y;
	double	tmp;
	int		i;

	x1 = resize_coord(x1, data->start_x, data->end_x);
	y1 = resize_coord(y1, data->start_y, data->end_y);
	x = 0;
	y = 0;
	i = 0;
	while (((x * x) + (y * y) <= 4) && i <= data->iter)
	{
		tmp = (x * x) - (y * y) + x1;
		y = (2 * x * y) + y1;
		x = tmp;
		i++;
	}
	return (i);
}

int	julia(t_data *data, double x1, double y1)
{
	double	x;
	double	y;
	double	tmp;
	int		i;

	x1 = resize_coord(x1, data->start_x, data->end_x);
	y1 = resize_coord(y1, data->start_y, data->end_y);
	x = x1;
	y = y1;
	i = 0;
	while (((x * x) + (y * y) <= 4) && i <= data->iter)
	{
		tmp = (x * x) - (y * y) + data->diff_x;
		y = (2 * x * y) + data->diff_y;
		x = tmp;
		i++;
	}
	return (i);
}
