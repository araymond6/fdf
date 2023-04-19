/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: araymond <araymond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 10:18:01 by araymond          #+#    #+#             */
/*   Updated: 2023/03/08 10:00:03 by araymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

// Handles horizontal movement of the image.
void	ft_slide_horizontal(void *param)
{
	t_fdf	*fdf;

	fdf = param;
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_LEFT)
		|| mlx_is_key_down(fdf->mlx, MLX_KEY_A))
	{
		ft_create_new_image(fdf);
		fdf->move_x -= 4;
		ft_draw_map(fdf, 0);
	}
	else if (mlx_is_key_down(fdf->mlx, MLX_KEY_RIGHT)
		|| mlx_is_key_down(fdf->mlx, MLX_KEY_D))
	{
		ft_create_new_image(fdf);
		fdf->move_x += 4;
		ft_draw_map(fdf, 0);
	}
}

// Handles vertical movement of the image.
void	ft_slide_vertical(void *param)
{
	t_fdf	*fdf;

	fdf = param;
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_UP)
		|| mlx_is_key_down(fdf->mlx, MLX_KEY_W))
	{
		ft_create_new_image(fdf);
		fdf->move_y -= 4;
		ft_draw_map(fdf, 0);
	}
	else if (mlx_is_key_down(fdf->mlx, MLX_KEY_DOWN)
		|| mlx_is_key_down(fdf->mlx, MLX_KEY_S))
	{
		ft_create_new_image(fdf);
		fdf->move_y += 4;
		ft_draw_map(fdf, 0);
	}
	ft_slide_horizontal(fdf);
}

// Handles the zoom of the image.
void	ft_zoom(void *param)
{
	t_fdf	*fdf;

	fdf = param;
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_I))
	{
		ft_create_new_image(fdf);
		fdf->h_offset += 4;
		fdf->v_offset = fdf->h_offset / 2;
		ft_draw_map(fdf, 0);
	}
	else if (mlx_is_key_down(fdf->mlx, MLX_KEY_O))
	{
		ft_create_new_image(fdf);
		if (!(fdf->h_offset < DEF_OFFSET))
		{
			fdf->h_offset -= 4;
			fdf->v_offset = fdf->h_offset / 2;
		}
		ft_draw_map(fdf, 0);
	}
}

// Main hook used for all keys functions.
void	ft_keysfunc1_hook(void *param)
{
	t_fdf	*fdf;

	fdf = param;
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(fdf->mlx);
	else if (mlx_is_key_down(fdf->mlx, MLX_KEY_SPACE)
		|| mlx_is_key_down(fdf->mlx, MLX_KEY_C))
	{
		ft_create_new_image(fdf);
		fdf->move_x = 0;
		fdf->move_y = 0;
		fdf->h_offset = DEF_OFFSET;
		fdf->v_offset = fdf->h_offset / 2;
		ft_draw_map(fdf, 0);
	}
	ft_slide_vertical(fdf);
	ft_zoom(fdf);
}

// Deletes the image and closes the window.
void	ft_close(void *param)
{
	t_fdf	*fdf;

	fdf = param;
	mlx_delete_image(fdf->mlx, fdf->img);
	mlx_close_window(fdf->mlx);
}
