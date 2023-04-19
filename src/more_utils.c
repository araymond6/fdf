/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   more_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: araymond <araymond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 10:36:17 by araymond          #+#    #+#             */
/*   Updated: 2023/03/08 09:54:45 by araymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

// Checks if string of string is not NULL and frees it. 
void	ft_checkstrstr(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i])
			free(str[i]);
		i++;
	}
	free(str);
	str = NULL;
}

// Shows controls on the screen.
void	ft_controls(void *param)
{
	t_fdf	*fdf;

	fdf = param;
	mlx_put_string(fdf->mlx, "Up/Down/Left/Right or WASD: Move image", 5, 5);
	mlx_put_string(fdf->mlx, "SPACE/C: Reset and center image", 5, 25);
	mlx_put_string(fdf->mlx, "I/O: Zoom in / Zoom out", 5, 45);
	mlx_put_string(fdf->mlx, "ESC: Close window", 5, 65);
}

// Deletes and creates a new image.
void	ft_create_new_image(t_fdf *fdf)
{
	mlx_delete_image(fdf->mlx, fdf->img);
	fdf->img = mlx_new_image(fdf->mlx, WIDTH, HEIGHT);
	if (!fdf->img)
		ft_graphic_error(fdf);
}
