/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: araymond <araymond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 10:46:35 by araymond          #+#    #+#             */
/*   Updated: 2023/03/08 09:52:12 by araymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	ft_malloc_error(t_fdf *fdf)
{
	ft_clear_fdf(fdf);
	printf("Malloc error");
	exit (EXIT_FAILURE);
}

int	main(int argc, char **argv)
{
	t_fdf	*fdf;
	int		x;

	x = 0;
	if (argc == 2)
	{
		fdf = ft_initiate_fdf();
		if (!fdf)
			ft_malloc_error(NULL);
		ft_map_parsing(argv[1], fdf);
		ft_create_window(fdf);
		ft_clear_fdf(fdf);
	}
	else
	{
		printf("Incorrect amount of arguments.");
		exit(EXIT_FAILURE);
	}
	exit(EXIT_SUCCESS);
}
