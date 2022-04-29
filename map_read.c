/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_read.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmabel <jmabel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 19:00:09 by jmabel            #+#    #+#             */
/*   Updated: 2022/04/29 20:00:16 by jmabel           ###   ########.fr       */
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
	return (fd);
}

static void	ft_define_column_row(t_fdf *fdf, t_pars *parser)
{
	int	ret;

	ret = 1;
	fdf->column = -1;
	fdf->row = 0;
	while (ret)
	{
		parser->line = get_next_line(parser->fd);
		if (parser->line == NULL)
			ret = 0;
		else
		{
			if (fdf->column == -1)
				fdf->column = ft_count_column(parser->line, ' ');
			else
			{
				if (ft_count_column(parser->line, ' ') != fdf->column)
					ft_error_map(parser, 'm');
			}
			(fdf->row)++;
		}
		free(parser->line);
	}
	close(parser->fd);
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

static void	ft_fill_color_map(t_fdf *fdf, t_pars *parser)
{
	int		ret;
	int		nb_line;

	fdf->max_alt = INT_MIN;
	fdf->min_alt = INT_MAX;
	ret = 1;
	nb_line = 0;
	while (ret)
	{
		parser->line = get_next_line(parser->fd);
		if (parser->line == NULL)
			ret = 0;
		else
			ft_define_map_value(fdf, parser, nb_line);
		nb_line++;
		free(parser->line);
	}
	close(parser->fd);
}

void	ft_read_map(t_fdf *fdf, int argc, char **argv)
{
	t_pars	parser;

	parser.fd = ft_open_map(argc, argv, 'f');
	if (parser.fd == -1)
		ft_exit_fdf('p');
	ft_define_column_row(fdf, &parser);
	if (fdf->row == 0)
		ft_error_map_close(&parser, 'm');
	if (ft_allocate_mem(&(fdf->map), fdf->row, fdf->column) == -1)
		ft_exit_fdf('p');
	if (ft_allocate_mem(&(fdf->color), fdf->row, fdf->column) == -1)
	{
		ft_free_int_array(fdf->map, fdf->row);
		ft_exit_fdf('p');
	}
	parser.fd = ft_open_map(argc, argv, 's');
	if (parser.fd == -1)
	{
		ft_free_int_array(fdf->map, fdf->row);
		ft_free_int_array(fdf->color, fdf->row);
		ft_exit_fdf('p');
	}	
	ft_fill_color_map(fdf, &parser);
}
