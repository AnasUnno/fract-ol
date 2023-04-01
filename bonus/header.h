/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: araji-af <araji-af@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 14:20:57 by araji-af          #+#    #+#             */
/*   Updated: 2023/03/23 14:07:53 by araji-af         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include <mlx.h>
# include <math.h>
# include <stdlib.h>
# include <unistd.h>

# define SIZE	500

typedef struct s_data {
	void	*mlx_ptr;
	void	*mlx_window;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		color;
	int		iter;
	double	scale;
	double	move_scale;
	double	start_x;
	double	start_y;
	double	end_x;
	double	end_y;
	int		identity;
}	t_data;

double	resize_coord(double coor, double start, double end);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
void	first_to_call(t_data *data);
void	initialise(t_data *data);
int		get_color(int i, t_data *data);
int		multibrot(t_data *data, double x1, double y1);
void	draw(t_data *data);
int		zoom(int key, int x, int y, t_data *data);
int		key_press(int key, t_data *data);
int		destroy(t_data *data);
void	zoom_in(double x0, double y0, t_data *data);
void	zoom_out(double x0, double y0, t_data *data);
void	key_up(t_data *data);
void	key_down(t_data *data);
void	key_left(t_data *data);
void	key_right(t_data *data);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);

#endif