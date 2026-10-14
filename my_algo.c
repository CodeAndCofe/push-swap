/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_algo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aferryat <aferryat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 16:27:35 by aferryat          #+#    #+#             */
/*   Updated: 2025/02/10 13:39:03 by aferryat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_pos(t_list *stack)
{
	int	i;

	i = 0;
	while (stack)
	{
		stack->pos = i;
		i++;
		stack = stack->next;
	}
}

static t_list	*bigest(t_list *stack)
{
	int		max;
	t_list	*big;
	t_list	*top;

	max = -2147483648;
	big = stack;
	top = stack;
	while (top)
	{
		if ((top)->val > max)
		{
			max = (top)->val;
			big = top;
		}
		top = (top)->next;
	}
	return (big);
}

static void	part_two(t_list **stack_a, t_list **stack_b, int size)
{
	int		val_big;
	t_list	*big;

	while ((*stack_b))
	{
		set_pos(*stack_b);
		big = bigest(*stack_b);
		val_big = big->val;
		if (big->pos <= size / 2)
		{
			while (val_big != (*stack_b)->val)
				rotate(stack_b, "rb\n");
		}
		else if (big->pos > size / 2)
		{
			while (val_big != (*stack_b)->val)
				reverse_rotate(stack_b, "rrb\n");
		}
		push(stack_b, stack_a, "pa\n");
		size--;
	}
}

static void	part_one(t_list **stack_a, t_list **stack_b, int range)
{
	int	i;

	i = 0;
	esy_sort(stack_a);
	while ((*stack_a))
	{
		if ((*stack_a)->index <= i)
		{
			push(stack_a, stack_b, "pb\n");
			i++;
		}
		else if ((*stack_a)->index <= i + range)
		{
			push(stack_a, stack_b, "pb\n");
			rotate(stack_b, "rb\n");
			i++;
		}
		else if (ft_mini_sort(*stack_a) == 1)
			reverse_rotate(stack_a, "rra\n");
		else
			rotate(stack_a, "ra\n");
	}
}

void	algo(t_list **stack_a, t_list **stack_b)
{
	int	size;
	int	range;

	size = linked_list_size(*stack_a);
	if (size <= 100)
		range = 13;
	else
		range = 38;
	part_one(stack_a, stack_b, range);
	part_two(stack_a, stack_b, size);
}
