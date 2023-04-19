/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: araymond <araymond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 13:00:41 by araymond          #+#    #+#             */
/*   Updated: 2023/03/09 10:10:28 by araymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

// Checks if the file name and content is good.
int	ft_check_name(char *arg)
{
	char	*str;

	str = ft_strrchr(arg, '.');
	if (!str)
		return (ERROR);
	if (ft_strncmp(str, ".fdf", ft_strlen(str) + 1) != 0)
		return (ERROR);
	return (SUCCESS);
}

// Adds the elements of the map that are good to fdf->map.
static int	ft_add_to_map(char **line, t_fdf *fdf)
{
	static int		x;
	int				counter;

	if (!fdf->map)
	{
		fdf->map = (int *)malloc(sizeof(int) * (fdf->max_x * fdf->max_y));
		if (!fdf->map)
			return (ERROR);
	}
	counter = 0;
	while (line[counter] && x < fdf->max_x * fdf->max_y)
	{
		fdf->map[x] = ft_atoi(line[counter]);
		if (fdf->map[x] < fdf->min_z)
			fdf->min_z = fdf->map[x];
		if (fdf->map[x] > fdf->max_z)
			fdf->max_z = fdf->map[x];
		x++;
		counter++;
	}
	return (SUCCESS);
}

// Checks if the line contains only numbers (Positive or negative).
int	ft_check_numbers(char **line, t_fdf *fdf)
{
	int		i;
	int		j;

	if (!line)
		return (ERROR);
	i = 0;
	while (line[i])
	{
		j = 0;
		if (line[i][j] == '-')
			j = 1;
		while (line[i][j])
		{
			if (!ft_isdigit(line[i][j]))
			{
				ft_checkstrstr(line);
				return (ERROR);
			}
			j++;
		}
		i++;
	}
	ft_add_to_map(line, fdf);
	ft_checkstrstr(line);
	return (SUCCESS);
}
