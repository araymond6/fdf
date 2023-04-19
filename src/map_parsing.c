/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: araymond <araymond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 14:44:29 by araymond          #+#    #+#             */
/*   Updated: 2023/03/09 10:12:53 by araymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

// Clears fdf and exits if there is a map error.
void	ft_map_exit(t_fdf *fdf)
{
	ft_clear_fdf(fdf);
	printf("Map error.");
	exit(EXIT_FAILURE);
}

// To shorten ft_count
int	ft_checks(t_fdf *fdf, char **split)
{
	int	i;

	i = 0;
	while (split[i])
		i++;
	if (!fdf->max_x)
		fdf->max_x = i;
	else if (i != fdf->max_x)
	{
		ft_checkstrstr(split);
		return (ERROR);
	}
	ft_checkstrstr(split);
	return (SUCCESS);
}

// Goes through the map and counts the elements.
int	ft_count(t_fdf *fdf, int fd)
{
	char	*line;
	char	*temp;
	char	**split;

	line = "";
	if (!line)
		return (ERROR);
	while (line)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		temp = ft_strtrim(line, "\n");
		if (!temp)
			ft_freestr(line, fdf);
		free(line);
		split = ft_split(temp, ' ');
		free(temp);
		if (!split)
			return (ERROR);
		if (!ft_checks(fdf, split))
			return (ERROR);
		fdf->max_y++;
	}
	return (SUCCESS);
}

// Verifies the file to make sure all the info stored is good.
int	ft_file_parsing(t_fdf *fdf, int fd)
{
	char	*line;
	char	*temp;
	char	**split;

	line = "";
	if (!line)
		return (ERROR);
	while (line)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		temp = ft_strtrim(line, "\n");
		if (!temp)
			ft_freestr(line, fdf);
		free(line);
		split = ft_split(temp, ' ');
		free(temp);
		if (!split)
			return (ERROR);
		if (!ft_check_numbers(split, fdf))
			return (ERROR);
	}
	return (SUCCESS);
}

// Checks if the argument provided is valid.
void	ft_map_parsing(char *arg, t_fdf *fdf)
{
	int	fd;

	fd = open(arg, O_RDONLY);
	if (fd == FD_ERROR || read(fd, NULL, 0)
		|| !ft_check_name(arg))
		ft_map_exit(fdf);
	if (!ft_count(fdf, fd))
	{
		close(fd);
		ft_map_exit(fdf);
	}
	close(fd);
	fd = open(arg, O_RDONLY);
	if (!ft_file_parsing(fdf, fd) || fdf->map == NULL
		|| (fdf->max_x == 1 && fdf->max_y == 1))
	{
		close(fd);
		ft_map_exit(fdf);
	}
	close(fd);
}
