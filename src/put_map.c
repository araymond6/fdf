/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: araymond <araymond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 10:16:09 by araymond          #+#    #+#             */
/*   Updated: 2023/03/08 09:58:10 by araymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

// Initiates a point to draw.
t_point	ft_initiate_point(t_fdf *fdf, int counter)
{
	t_point	point;

	point.x = (counter % fdf->max_x);
	point.y = (counter / fdf->max_x);
	point.z = fdf->map[counter];
	point.iso_x = point.x + (point.x - point.y) * \
	(fdf->h_offset / 2) + (WIDTH / 2 + fdf->move_x);
	point.iso_y = point.y + (point.x + point.y - point.z) * \
	(fdf->v_offset / 2) + (HEIGHT / 4 + fdf->move_y);
	return (point);
}

// Loop to draw the map on the screen.
int	ft_draw_map(t_fdf *fdf, int counter)
{
	t_point	point;
	t_point	next_x;
	t_point	next_y;

	while (counter <= fdf->max_x * fdf->max_y)
	{
		point = ft_initiate_point(fdf, counter);
		if (counter + 1 < fdf->max_x * fdf->max_y)
			next_x = ft_initiate_point(fdf, counter + 1);
		else
			break ;
		ft_draw_line(fdf, point, next_x);
		if (counter + fdf->max_x < fdf->max_x * fdf->max_y)
		{
			next_y = ft_initiate_point(fdf, counter + fdf->max_x);
			ft_draw_line(fdf, point, next_y);
			ft_draw_line(fdf, next_y, point);
		}
		counter++;
	}
	if (mlx_image_to_window(fdf->mlx, fdf->img, 0, 0) == -1)
		ft_graphic_error(fdf);
	return (SUCCESS);
}

/* Creates MLX Window and handles all the hooks. 
Also responsible for terminating MLX handle. */
int	ft_create_window(t_fdf *fdf)
{
	fdf->mlx = mlx_init(WIDTH, HEIGHT, "FDF", false);
	if (!fdf->mlx)
		ft_graphic_error(fdf);
	fdf->img = mlx_new_image(fdf->mlx, WIDTH, HEIGHT);
	if (!fdf->img)
		ft_graphic_error(fdf);
	ft_draw_map(fdf, 0);
	ft_controls(fdf);
	if (!mlx_loop_hook(fdf->mlx, &ft_keysfunc1_hook, fdf))
		ft_graphic_error(fdf);
	mlx_close_hook(fdf->mlx, &ft_close, fdf);
	mlx_loop(fdf->mlx);
	mlx_terminate(fdf->mlx);
	return (SUCCESS);
}
