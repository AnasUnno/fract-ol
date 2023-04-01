/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: araji-af <araji-af@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 17:30:07 by araji-af          #+#    #+#             */
/*   Updated: 2023/03/23 14:10:31 by araji-af         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	multibrot(t_data *data, double x1, double y1)
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
	while (((x * x) + (y * y) < 4) && i <= data->iter)
	{
		tmp = (x * x * x) - (2 * x * y * y) - 3 * x *(y * y) - x1;
		y = (3 * x * x * y) - 3 * (y * y * y) + y1;
		x = tmp;
		i++;
	}
	return (i);
}
