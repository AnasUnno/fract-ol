/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: araji-af <araji-af@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 17:27:20 by araji-af          #+#    #+#             */
/*   Updated: 2023/04/05 17:03:54 by araji-af         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	initialise(t_data *data, char **av)
{
	wich_frac(data, av[1]);
	data->mlx_ptr = mlx_init();
	data->mlx_window = mlx_new_window(data->mlx_ptr, SIZE, SIZE, "fractol");
	data->img = mlx_new_image(data->mlx_ptr, SIZE, SIZE);
	data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel,
			&data->line_length, &data->endian);
	data->iter = 70;
	data->diff_x = 0.285;
	data->diff_y = 0.01;
	data->scale = 0.5;
	data->move_scale = 0.2;
	data->start_x = -2;
	data->start_y = -2;
	data->end_x = 2;
	data->end_y = 2;
	data->color = 0x640C32;
	data->lock = 1;
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

void	protect(int ac, char **av)
{
	int	i;

	if (ac <= 1 || ac != 2)
	{
		ft_putstr_fd("please pick one of these : mandelbrot, julia.\n", 2);
		exit (1);
	}
	i = 1;
	while (i < ac)
	{
		if (!av[i] || !*av[i])
		{
			ft_putstr_fd("please pick one of these : mandelbrot, julia.\n", 2);
			exit (1);
		}
		i++;
	}
}
