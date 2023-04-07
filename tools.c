/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: araji-af <araji-af@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 14:28:52 by araji-af          #+#    #+#             */
/*   Updated: 2023/04/01 22:54:55 by araji-af         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double	resize_coord(double coor, double start, double end)
{
	return ((coor / SIZE) * (end - start) + start);
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	first_to_call(t_data *data, char **av)
{
	initialise(data, av);
	mlx_mouse_hook(data->mlx_window, zoom, data);
	mlx_hook(data->mlx_window, 02, 0, key_press, data);
	mlx_hook(data->mlx_window, 17, 0, destroy, data);
	mlx_hook(data->mlx_window, 6, 0, julia_changer, data);
	mlx_loop(data->mlx_ptr);
}

int	get_color(int i, t_data *data)
{
	int	r;
	int	g;
	int	b;

	if (i >= data->iter)
		return (0);
	r = i * (1 - sin(data->color));
	b = 4 * i * (2 + cos(data->color));
	g = 3 * i * (1 + cos(data->color));
	return (r << 16 | g << 8 | b);
}

void	draw(t_data *data)
{
	double		i;
	int			x;
	int			y;

	x = 0;
	while (x < SIZE)
	{
		y = 0;
		while (y < SIZE)
		{
			if (data->identity == 1)
				i = mandelbrot(data, x, y);
			else if (data->identity == 2)
				i = julia(data, x, y);
			my_mlx_pixel_put(data, x, y, get_color(i, data));
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(data->mlx_ptr, data->mlx_window, data->img, 0, 0);
}
