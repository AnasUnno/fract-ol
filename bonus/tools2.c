/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: araji-af <araji-af@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 17:27:20 by araji-af          #+#    #+#             */
/*   Updated: 2023/03/23 14:08:05 by araji-af         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	initialise(t_data *data)
{
	data->mlx_ptr = mlx_init();
	data->mlx_window = mlx_new_window(data->mlx_ptr, SIZE, SIZE, "fractol");
	data->img = mlx_new_image(data->mlx_ptr, SIZE, SIZE);
	data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel,
			&data->line_length, &data->endian);
	data->iter = 100;
	data->scale = 0.5;
	data->move_scale = 0.2;
	data->start_x = -2;
	data->start_y = -2;
	data->end_x = 2;
	data->end_y = 2;
	data->color = 0x701250;
	draw(data);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	unsigned char	*p1;
	unsigned char	*p2;

	p1 = (unsigned char *)s1;
	p2 = (unsigned char *)s2;
	while (*p1 && *p2 && (*p1 == *p2))
	{
		p1++;
		p2++;
	}
	return (*p1 - *p2);
}

void	ft_putchar_fd(char c, int fd)
{
	write (fd, &c, 1);
}

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	if (s == NULL)
		return ;
	i = 0;
	while (s[i])
	{
		ft_putchar_fd(s[i], fd);
		i++;
	}
}
