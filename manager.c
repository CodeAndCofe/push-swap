/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manager.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aferryat <aferryat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 11:37:45 by aferryat          #+#    #+#             */
/*   Updated: 2025/02/09 13:43:45 by aferryat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	empty_stack(t_list **stack)
{
	t_list	*l;
	t_list	*s;

	if (stack == NULL)
		return ;
	l = *stack;
	s = *stack;
	while (s != NULL)
	{
		free(l);
		s = s->next;
		l = s;
	}
}

static t_list	*fill_stack(char **arr)
{
	t_list	*list;
	t_list	*new;
	int		i;

	i = 0;
	new = malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	list = new;
	while (arr[i])
	{
		if (ft_atoi(arr[i]) > 2147483647 || ft_atoi(arr[i]) < -2147483648)
			return (empty_stack(&list), NULL);
		new->val = ft_atoi(arr[i]);
		if (arr[i + 1])
			new->next = malloc(sizeof(t_list));
		else
			new->next = NULL;
		new = new->next;
		i++;
	}
	new = list;
	return (new);
}

void	manager(char *str)
{
	char	**new;
	int		i;
	t_list	*stack_a;
	t_list	*stack_b;

	i = 0;
	new = ft_splite(str);
	if (new == NULL)
		return ;
	stack_a = fill_stack(new);
	stack_b = NULL;
	while (new[i])
		i++;
	splite_field(new, i);
	if (stack_a == NULL)
		return (write(2, "Error\n", 6), empty_stack(NULL));
	if (is_sorted(stack_a) == 1)
		return (empty_stack(&stack_a));
	if (is_double(stack_a) == -1)
		return (write(2, "Error\n", 6), empty_stack(&stack_a));
	start_sort(&stack_a, &stack_b);
	empty_stack(&stack_a);
}
