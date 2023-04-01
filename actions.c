/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: araji-af <araji-af@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 12:51:48 by araji-af          #+#    #+#             */
/*   Updated: 2023/04/01 18:10:28 by araji-af         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	zoom(int key, int x, int y, t_data *data)
{
	double	x0;
	double	y0;

	x0 = resize_coord(x, data->start_x, data->end_x);
	y0 = resize_coord(y, data->start_y, data->end_y);
	if (key == 5)
		zoom_in(x0, y0, data);
	if (key == 4)
		zoom_out(x0, y0, data);
	return (0);
}

void	zoom_in(double x0, double y0, t_data *data)
{
	data->iter += 10;
	data->start_x += x0;
	data->start_y += y0;
	data->end_x += x0;
	data->end_y += y0;
	data->start_x *= data->scale;
	data->start_y *= data->scale;
	data->end_x *= data->scale;
	data->end_y *= data->scale;
	data->move_scale *= data->scale;
	draw(data);
}

void	zoom_out(double x0, double y0, t_data *data)
{
	data->start_x /= data->scale;
	data->start_y /= data->scale;
	data->end_x /= data->scale;
	data->end_y /= data->scale;
	data->iter -= 10;
	data->start_x -= x0;
	data->start_y -= y0;
	data->end_x -= x0;
	data->end_y -= y0;
	data->move_scale /= data->scale;
	draw(data);
}

int	key_press(int key, t_data *data)
{
	if (key == 49)
		data->lock *= -1;
	if (key == 126)
		key_up(data);
	if (key == 125)
		key_down(data);
	if (key == 124)
		key_right(data);
	if (key == 123)
		key_left(data);
	if (key == 35)
	{
		data->color += 5;
		draw(data);
	}
	if (key == 53)
		destroy(data);
	return (0);
}

int	destroy(t_data *data)
{
	mlx_destroy_image(data->mlx_ptr, data->img);
	mlx_destroy_window(data->mlx_ptr, data->mlx_window);
	data->mlx_ptr = NULL;
	exit (0);
}
