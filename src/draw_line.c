/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: araymond <araymond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 13:42:05 by araymond          #+#    #+#             */
/*   Updated: 2023/03/08 09:55:25 by araymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	ft_put_pixel(t_fdf *fdf, t_point point)
{
	if (!(point.iso_x >= WIDTH || point.iso_y >= HEIGHT
			|| point.iso_x < 0 || point.iso_y < 0))
		mlx_put_pixel(fdf->img, point.iso_x, point.iso_y, -1);
}

t_calc	ft_initiate_calc(t_point point, t_point next)
{
	t_calc	calc;

	calc.dx = fabs(next.iso_x - point.iso_x);
	if (point.iso_x < next.iso_x)
		calc.sx = 1;
	else
		calc.sx = -1;
	calc.dy = -fabs(next.iso_y - point.iso_y);
	if (point.iso_y < next.iso_y)
		calc.sy = 1;
	else
		calc.sy = -1;
	calc.slope_error = calc.dx + calc.dy;
	return (calc);
}

void	ft_draw_line(t_fdf *fdf, t_point point, t_point next)
{
	t_calc	calc;

	calc = ft_initiate_calc(point, next);
	while (point.iso_x <= next.iso_x)
	{
		ft_put_pixel(fdf, point);
		if (point.iso_x == next.iso_x && point.iso_y == next.iso_y)
			break ;
		calc.e2 = 2 * calc.slope_error;
		if (calc.e2 >= calc.dy)
		{
			if (point.iso_x == next.iso_x)
				break ;
			calc.slope_error += calc.dy;
			point.iso_x += calc.sx;
		}
		else if (calc.e2 <= calc.dx)
		{
			if (point.iso_y == next.iso_y)
				break ;
			calc.slope_error += calc.dx;
			point.iso_y += calc.sy;
		}
	}
}
