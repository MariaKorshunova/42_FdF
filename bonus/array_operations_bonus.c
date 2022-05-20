/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_operations_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmabel <jmabel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 19:39:52 by jmabel            #+#    #+#             */
/*   Updated: 2022/05/20 19:40:00 by jmabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

int	ft_count_column(char const *s, char c)
{
	int	count;
	int	i;
	int	len;

	len = (int)ft_strlen(s);
	i = 0;
	count = 0;
	if (len == 0)
		return (count);
	if (s[len - 1] == '\n')
		len--;
	while (i < len)
	{
		if (s[i] != c && (s[i + 1] == c
				|| s[i + 1] == '\0' || s[i + 1] == '\n'))
			count++;
		i++;
	}
	return (count);
}

void	ft_free_int_array(int **arr, int row)
{
	int	i;

	i = 0;
	while (i < row)
		free(arr[i++]);
	free(arr);
}

void	ft_free_char_array(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
		free(arr[i++]);
	free(arr);
}
