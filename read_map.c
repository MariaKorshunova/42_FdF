/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmabel <jmabel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 18:13:17 by jmabel            #+#    #+#             */
/*   Updated: 2022/03/20 19:52:13 by jmabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	ft_open_map(int argc, char **argv)
{
	int		fd;
	size_t	len;

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
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		perror("Error");
		exit (1);
	}
	return (fd);
}

static void	read_row(t_fdf *fdf, char **line, int column)
{
	char	**row;
	int		line_column;

	line_column = ft_str_count(*line, ' ');
	if (column != line_column)
	{
		ft_putstr_fd("Error: Invalid map\n", 2);
		//clear fdf.maps
		//clear fdf.colors
		free(*line);
		close(fdf->fd);
		exit (1);
	}
	row = ft_split(*line, ' ');
	if (!row)
	{
		perror("Error");
		//очистить fdf.maps
		//clear fdf.colors
		free(*line);
		close(fdf->fd);
		exit (1);
	}
	// ft_read_cell(fdf, row); Just do it :-)
	ft_free_char_array(row, line_column);
}

void	ft_read_map(t_fdf *fdf, int argc, char **argv)
{
	int		ret;
	char	*line;
	int		column;

	(void) fdf;
	fdf->fd = ft_open_map(argc, argv);
	ret = 1;
	column = -1;
	while (ret)
	{
		line = get_next_line(fdf->fd);
		if (line == NULL)
			ret = 0;
		else
		{
			if (column == -1)
				column = ft_str_count(line, ' ');
			read_row(fdf, &line, column);
		}
		free(line);
	}
	close(fdf->fd);
}
