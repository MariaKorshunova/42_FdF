/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base16.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmabel <jmabel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 20:04:51 by jmabel            #+#    #+#             */
/*   Updated: 2022/04/24 20:27:02 by jmabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	ft_str_tolower(char **str)
{
	int	i;

	i = 0;
	while ((*str)[i] != '\0')
	{
		(*str)[i] = ft_tolower((*str)[i]);
		i++;
	}
}

static int	ft_define_ascii_interval(int c)
{
	if (c >= '0' && c <= '9')
		return (c - 48);
	else if (c >= 'a' && c <= 'f')
		return (c - 'a' + 10);
	return (0);
}

static int	ft_create_nb_base_16(char *str, int *i, long long *nb)
{
	int	nb_digit;

	nb_digit = 0;
	while (str[*i] == '0')
		(*i)++;
	while ((str[*i] >= '0' && str[*i] <= '9')
		|| (str[*i] >= 'a' && str[*i] <= 'f'))
	{
		*nb = 16 * (*nb) + ft_define_ascii_interval(str[*i]);
		(*i)++;
		nb_digit++;
	}
	while (ft_isprint(str[*i]) == 0 && str[*i] != '\0')
		(*i)++;
	return (nb_digit);
}

int	ft_atoi_base_16(t_fdf *fdf, char *str, char **map_line, char **cell)
{
	int			i;
	long long	nb;
	int			nb_digit;

	i = 0;
	nb = 0;
	if (!str)
		return (0xffffff);
	while (!(ft_isprint(str[i])))
		i++;
	if (str[i++] != '0')
		ft_error_allocate_cell(fdf, map_line, cell, 'm');
	if (str[i++] != 'x')
		ft_error_allocate_cell(fdf, map_line, cell, 'm');
	ft_str_tolower(&str);
	nb_digit = ft_create_nb_base_16(str, &i, &nb);
	if (str[i] != '\0' || nb_digit > 6)
		ft_error_allocate_cell(fdf, map_line, cell, 'm');
	return (nb);
}
