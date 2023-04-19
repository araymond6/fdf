/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: araymond <araymond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 10:54:13 by araymond          #+#    #+#             */
/*   Updated: 2023/03/09 10:17:03 by araymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <math.h>
# include <stdio.h>
# include <fcntl.h>
# include <stdbool.h>
# include "../libft/libft.h"
# include "../libft/get_next_line.h"
# include "../include/MLX42/include/MLX42/MLX42.h"

// ERROR or SUCCESS
# define ERROR 0
# define SUCCESS 1
# define FD_ERROR -1
# define INT_ERROR -1

// IMAGE WIDTH / HEIGHT and default offset for generating map
# define WIDTH 2000
# define HEIGHT 1000
# define DEF_OFFSET 32

// holds mlx, img and the map
typedef struct s_fdf
{
	mlx_t		*mlx;
	mlx_image_t	*img;
	int			*map;
	int			max_x;
	int			max_y;
	int			min_z;
	int			max_z;
	int			move_x;
	int			move_y;
	float		h_offset;
	float		v_offset;
}	t_fdf;

// Holds individual point on the map. To pass in functions with calculations.
typedef struct s_point
{
	int		x;
	int		y;
	int		z;
	float	iso_x;
	float	iso_y;
}	t_point;

//
typedef struct s_calc
{
	int	dx;
	int	dy;
	int	sx;
	int	sy;
	int	e2;
	int	slope_error;
}	t_calc;

// Parsing Functions
void	ft_map_parsing(char *arg, t_fdf *fdf);
int		ft_check_numbers(char **line, t_fdf *fdf);

//Functions that use MLX42
void	ft_draw_line(t_fdf *fdf, t_point point, t_point next);
int		ft_create_window(t_fdf *fdf);
void	ft_scroll_hook(double y_delta, double x_delta, void *param);
void	ft_keysfunc1_hook(void *param);
bool	ft_keysfunc2_hook(void *param);
int		ft_draw_map(t_fdf *fdf, int counter);

// Utils
void	ft_checkstr(char *str);
void	ft_checkstrstr(char **str);
int		ft_create_rgba(int r, int g, int b, int a);
int		ft_count(t_fdf *fdf, int fd);
t_fdf	*ft_initiate_fdf(void);
void	ft_clear_fdf(t_fdf *fdf);
void	ft_freestr(char *line, t_fdf *fdf);
void	ft_graphic_error(t_fdf *fdf);
int		ft_check_name(char *arg);

// Windows Functions
void	ft_close(void *param);
void	ft_controls(void *param);
void	ft_create_new_image(t_fdf *fdf);

#endif