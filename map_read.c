/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_read.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmabel <jmabel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 19:00:09 by jmabel            #+#    #+#             */
/*   Updated: 2022/04/24 20:37:21 by jmabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	ft_open_map(int argc, char **argv, char check)
{
	int		fd;
	size_t	len;

	if (check == 'f')
	{
		if (argc != 2)
		{
			ft_putstr_fd("Error: Invalid number of arguments\n", 2);
			exit (1);
		}
		len = ft_strlen(argv[1]);
		if (argv[1][len - 1] != 'f' || argv[1][len - 2] != 'd'
			|| argv[1][len - 3] != 'f' || argv[1][len - 4] != '.')
		{
			ft_putstr_fd("Error: Invalid file extension\n", 2);
			exit (1);
		}
	}
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		perror("Error");
		exit (1);
	}
	return (fd);
}

static void	ft_define_column_row(t_fdf *fdf)
{
	int	ret;

	ret = 1;
	fdf->column = -1;
	fdf->row = 0;
	while (ret)
	{
		fdf->line = get_next_line(fdf->fd);
		if (fdf->line == NULL)
			ret = 0;
		else
		{
			if (fdf->column == -1)
				fdf->column = ft_count_column(fdf->line, ' ');
			else
			{
				if (ft_count_column(fdf->line, ' ') != fdf->column)
					ft_error_map(fdf, 'm');
			}
			(fdf->row)++;
		}
		free(fdf->line);
	}
	close(fdf->fd);
}

static int	ft_allocate_mem(int ***arr, int row, int column)
{
	int	i;

	*arr = (int **)malloc(row * sizeof(int *));
	if (!(*arr))
		return (-1);
	i = 0;
	while (i < row)
	{
		(*arr)[i] = (int *)malloc(column * sizeof(int));
		if (!(*arr)[i])
		{
			ft_free_int_array(*arr, i - 1);
			return (-1);
		}
		i++;
	}
	return (0);
}

static void	ft_fill_color_map(t_fdf *fdf)
{
	int		ret;
	int		nb_line;

	ret = 1;
	nb_line = 0;
	while (ret)
	{
		fdf->line = get_next_line(fdf->fd);
		if (fdf->line == NULL)
			ret = 0;
		else
			ft_define_map_value(fdf, nb_line);
		nb_line++;
		free(fdf->line);
	}
	close(fdf->fd);
}

void	ft_read_map(t_fdf *fdf, int argc, char **argv)
{
	fdf->fd = ft_open_map(argc, argv, 'f');
	ft_define_column_row(fdf);
	if (fdf->row == 0)
		ft_error_map(fdf, 'm');
	if (ft_allocate_mem(&(fdf->map), fdf->row, fdf->column) == -1)
	{
		perror("Error");
		exit (1);
	}
	if (ft_allocate_mem(&(fdf->color), fdf->row, fdf->column) == -1)
	{
		ft_free_int_array(fdf->map, fdf->row);
		perror("Error");
		exit (1);
	}
	fdf->fd = ft_open_map(argc, argv, 's');
	ft_fill_color_map(fdf);
	ft_print_int_array(fdf->map, fdf->row, fdf->column, 10);
	ft_print_int_array(fdf->color, fdf->row, fdf->column, 16);
}
