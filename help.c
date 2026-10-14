/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aferryat <aferryat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 16:32:18 by aferryat          #+#    #+#             */
/*   Updated: 2025/02/13 12:00:33 by aferryat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_index(t_list *elm, t_list *top)
{
	while (top)
	{
		if (elm->val > top->val)
			elm->index++;
		top = top->next;
	}
}

void	esy_sort(t_list **list)
{
	t_list	*tmp;
	t_list	*top;

	tmp = *list;
	top = *list;
	while (tmp)
	{
		tmp->index = 0;
		set_index(tmp, top);
		tmp = tmp->next;
	}
}

int	find_min(t_list *stack)
{
	int	min;

	min = stack->val;
	while (stack)
	{
		if (stack->val < min)
			min = stack->val;
		stack = stack->next;
	}
	return (min);
}

int	find_min_index(t_list *stack)
{
	int	min;
	int	i;

	i = 0;
	min = stack->val;
	while (stack)
	{
		if (stack->val < min)
		{
			min = stack->val;
			i++;
		}
		stack = stack->next;
	}
	return (i);
}
