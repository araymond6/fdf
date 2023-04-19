/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: araymond <araymond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 09:28:51 by araymond          #+#    #+#             */
/*   Updated: 2023/03/21 16:20:07 by araymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

// Checks is string is NULL and frees it.
void	ft_checkstr(char *str)
{
	if (!str)
		free(str);
}

//Initialises and mallocs t_fdf with NULL values
t_fdf	*ft_initiate_fdf(void)
{
	t_fdf	*fdf;

	fdf = malloc(sizeof(t_fdf));
	if (!fdf)
		return (NULL);
	fdf->max_x = 0;
	fdf->max_y = 0;
	fdf->min_z = 0;
	fdf->max_z = 0;
	fdf->move_x = 0;
	fdf->move_y = 0;
	fdf->h_offset = DEF_OFFSET;
	fdf->v_offset = fdf->h_offset / 2;
	fdf->map = NULL;
	fdf->mlx = NULL;
	fdf->img = NULL;
	return (fdf);
}

// De-allocates t_fdf *fdf.
void	ft_clear_fdf(t_fdf *fdf)
{
	if (fdf)
	{
		if (fdf->map)
			free(fdf->map);
		free(fdf);
	}
}

// Frees a string and exits on map error.
void	ft_freestr(char *str, t_fdf *fdf)
{
	free(str);
	ft_clear_fdf(fdf);
	printf("Map error.");
	exit(EXIT_FAILURE);
}

// Exits on graphic error.
void	ft_graphic_error(t_fdf *fdf)
{
	ft_close(fdf);
	ft_clear_fdf(fdf);
	printf("Graphic error.");
	exit(EXIT_FAILURE);
}
