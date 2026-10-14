/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aferryat <aferryat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 11:32:13 by aferryat          #+#    #+#             */
/*   Updated: 2025/02/03 14:12:55 by aferryat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static char	*joiner(char **arr_str, int count, int arg_count)
{
	char	*ptr;
	int		i;
	int		j;
	int		t;

	i = 1;
	j = 0;
	t = 0;
	ptr = malloc (count + arg_count);
	if (ptr == NULL)
		return (NULL);
	while (arr_str[i])
	{
		while (arr_str[i][j])
		{
			ptr[t++] = arr_str[i][j];
			j++;
		}
		if (i < arg_count - 1)
			ptr[t++] = ' ';
		j = 0;
		i++;
	}
	ptr[t++] = '\0';
	return (ptr);
}

char	*ft_string(char **arr_str)
{
	int		i;
	int		count;
	char	*str;

	i = 0;
	count = 0;
	if (arr_str == NULL)
		return (NULL);
	while (arr_str[i])
	{
		count += ft_strlen(arr_str[i]);
		i++;
	}
	str = joiner(arr_str, count, i);
	return (str);
}
