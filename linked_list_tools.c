/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list_tools.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aferryat <aferryat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 15:23:14 by aferryat          #+#    #+#             */
/*   Updated: 2025/02/12 12:41:19 by aferryat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	linked_list_size(t_list *list)
{
	int	i;

	i = 0;
	while (list != NULL)
	{
		list = list->next;
		i++;
	}
	return (i);
}

int	is_double(t_list *list)
{
	t_list	*s;

	while (list->next)
	{
		s = list->next;
		while (s)
		{
			if (s->val == list->val)
				return (-1);
			s = s->next;
		}
		list = list->next;
	}
	return (0);
}

int	is_sorted(t_list *list)
{
	while (list->next != NULL)
	{
		if (list->val >= list->next->val)
			return (0);
		list = list->next;
	}
	return (1);
}
