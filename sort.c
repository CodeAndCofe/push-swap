/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aferryat <aferryat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 15:17:44 by aferryat          #+#    #+#             */
/*   Updated: 2025/02/13 11:59:32 by aferryat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_mini_sort(t_list *list)
{
	int	count;
	int	espace;

	count = 0;
	espace = 0;
	while (list && list->next)
	{
		espace = list->val - list->next->val;
		if (espace == 2 || espace == 3 || espace == 4)
			count++;
		list = list->next;
	}
	if (count >= 15 && count <= 498)
		return (1);
	return (0);
}

void	swap_3(t_list **list)
{
	int	a;
	int	b;
	int	c;

	a = (*list)->val;
	b = (*list)->next->val;
	c = (*list)->next->next->val;
	if (a > b && b < c && a < c)
		swap_a(list, "sa\n");
	else if (a > b && b > c)
	{
		swap_a(list, "sa\n");
		reverse_rotate(list, "rra\n");
	}
	else if (a > b && b < c && a > c)
		rotate(list, "ra\n");
	else if (a < b && b > c && a < c)
	{
		swap_a(list, "sa\n");
		rotate(list, "ra\n");
	}
	else if (a < b && b > c && a > c)
		reverse_rotate(list, "rra\n");
}

void	sort_4_5(t_list **stack_a, t_list **stack_b)
{
	int		size;
	int		min;
	int		i;

	size = linked_list_size(*stack_a);
	i = 0;
	while (size > 3)
	{
		min = find_min(*stack_a);
		i = find_min_index(*stack_a);
		while ((*stack_a)->val != min && i <= size / 2)
			rotate(stack_a, "ra\n");
		while ((*stack_a)->val != min && i > size / 2)
			reverse_rotate(stack_a, "rra\n");
		push(stack_a, stack_b, "pb\n");
		size--;
	}
	if (is_sorted(*stack_a) == 0)
		swap_3(stack_a);
	while (*stack_b)
		push(stack_b, stack_a, "pa\n");
}

void	start_sort(t_list **stack_a, t_list **stack_b)
{
	int	len;

	len = linked_list_size(*stack_a);
	if (len == 2)
		swap_a(stack_a, "sa\n");
	else if (len == 3)
		swap_3(&(*stack_a));
	else if (len < 6)
		sort_4_5(&(*stack_a), &(*stack_b));
	else
		algo(stack_a, stack_b);
}
