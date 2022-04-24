/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base10.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmabel <jmabel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 17:12:58 by jmabel            #+#    #+#             */
/*   Updated: 2022/04/24 20:12:18 by jmabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	ft_atoi_sign(const char *str, int *i)
{
	while (!(ft_isprint(str[*i])))
		(*i)++;
	if (str[*i] == '+')
		(*i)++;
	else if (str[*i] == '-')
	{
		(*i)++;
		return (-1);
	}
	return (1);
}

static	int	ft_create_nb(const char *str, int *i, long long *nb)
{
	size_t			nb_digit;

	nb_digit = 0;
	while (str[*i] == '0')
		(*i)++;
	while (str[*i] >= '0' && str[*i] <= '9')
	{
		*nb = 10 * (*nb) + str[(*i)++] - '0';
		nb_digit++;
	}
	while (ft_isprint(str[*i]) == 0 && str[*i] != '\0')
		(*i)++;
	return (nb_digit);
}

int	ft_atoi_base_10(t_fdf *fdf, char *str, char **map_line, char **cell)
{
	int				i;
	int				minus;
	long long		nb;
	size_t			nb_digit;

	i = 0;
	nb = 0;
	nb_digit = 0;
	minus = ft_atoi_sign(str, &i);
	if (str[i] == '\0')
		ft_error_allocate_cell(fdf, map_line, cell, 'm');
	nb_digit = ft_create_nb(str, &i, &nb);
	if (str[i] != '\0' || (nb > 2147483647 && minus == 1)
		|| (nb > 2147483648 && minus == -1) || nb_digit > 11)
		ft_error_allocate_cell(fdf, map_line, cell, 'm');
	return (minus * nb);
}
