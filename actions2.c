/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: araji-af <araji-af@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 14:54:15 by araji-af          #+#    #+#             */
/*   Updated: 2023/04/01 16:11:01 by araji-af         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	key_up(t_data *data)
{
	data->start_y -= data->move_scale;
	data->end_y -= data->move_scale;
	draw(data);
}

void	key_down(t_data *data)
{
	data->start_y += data->move_scale;
	data->end_y += data->move_scale;
	draw(data);
}

void	key_right(t_data *data)
{
	data->start_x += data->move_scale;
	data->end_x += data->move_scale;
	draw(data);
}

void	key_left(t_data *data)
{
	data->start_x -= data->move_scale;
	data->end_x -= data->move_scale;
	draw(data);
}
