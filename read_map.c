/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmabel <jmabel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 18:13:17 by jmabel            #+#    #+#             */
/*   Updated: 2022/03/21 19:53:03 by jmabel           ###   ########.fr       */
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

void	ft_define_column_row(t_map *map)
{
	int	ret;

	ret = 1;
	map->column = -1;
	map->row = 0;
	while (ret)
	{
		map->line = get_next_line(map->fd);
		if (map->line == NULL)
			ret = 0;
		else
		{
			if (map->column == -1)
				map->column = ft_count_column(map->line, ' ');
			else
			{
				if (ft_count_column(map->line, ' ') != map->column)
					ft_error_map(map, 'm');
			}
			(map->row)++;
		}
		free(map->line);
	}
	close(map->fd);
}

void	ft_read_map(t_fdf *fdf, int argc, char **argv)
{
	t_map	map;

	(void) fdf;
	map.fd = ft_open_map(argc, argv);
	ft_define_column_row(&map);
	if (map.column == 0 || map.row == 0)
		ft_error_map(&map, 'm');
}
