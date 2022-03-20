/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmabel <jmabel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 19:52:53 by jmabel            #+#    #+#             */
/*   Updated: 2022/03/20 19:53:23 by jmabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_str_count(char const *s, char c)
{
	int	count;
	int	i;

	i = 0;
	count = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
			count++;
		i++;
	}
	return (count);
}

void	ft_free_char_array(char **arr, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
		free(arr[i++]);
	free(arr);
}
