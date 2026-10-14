/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aferryat <aferryat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 10:55:30 by aferryat          #+#    #+#             */
/*   Updated: 2025/02/13 12:03:02 by aferryat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ifempty(char *str)
{
	int	f;
	int	i;

	i = 0;
	f = 0;
	while (str[i])
	{
		if (str[i] != ' ' && str[i] != '	')
			f = 1;
		if ((str[i] == '	' || str[i] == ' ') && f == 0)
			f = -1;
		i++;
	}
	return (f);
}

static int	checker(char *str)
{
	int	i;

	i = 0;
	if (ifempty(str) == -1 || str[i] == '\0')
		return (-1);
	while (str[i])
	{
		if (str[i] == '+' || str[i] == '-')
		{
			if (str[i + 1] >= '0' && str[i + 1] <= '9')
				i++;
			else
				return (-1);
		}
		if (str[i] != ' ')
		{
			if (str[i] < '0' || str[i] > '9')
				return (-1);
		}
		else if (str[i] == '	')
			return (-1);
		i++;
	}
	return (1);
}

static int	arg_filter(char **arv)
{
	int	i;

	i = 1;
	while (arv[i])
	{
		if (checker(arv[i]) == -1)
			return (-1);
		i++;
	}
	return (1);
}

int	main(int arc, char **arv)
{
	char	*str;
	int		res;

	if (arc < 2)
		return (0);
	res = arg_filter(arv);
	if (res == -1)
	{
		write(2, "Error\n", 6);
		return (-1);
	}
	str = ft_string(arv);
	if (str == NULL)
		return (0);
	manager(str);
	free(str);
	return (0);
}
