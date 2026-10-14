/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_move.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aferryat <aferryat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 18:48:05 by aferryat          #+#    #+#             */
/*   Updated: 2025/02/03 14:18:07 by aferryat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_two(t_list **list)
{
	int		rate;
	int		temp;
	t_list	*current;

	current = *list;
	temp = current->val;
	rate = current->index;
	current->val = current->next->val;
	current->index = current->next->index;
	current->next->val = temp;
	current->next->index = rate;
}

void	swap_a(t_list **list, char *s)
{
	swap_two(&(*list));
	ft_putstr(s);
}

void	rotate(t_list **list, char *s)
{
	t_list	*temp;

	temp = *list;
	while (temp->next != NULL)
	{
		swap_two(&temp);
		temp = temp->next;
	}
	ft_putstr(s);
}

void	reverse_rotate(t_list **list, char *s)
{
	t_list	*temp;
	t_list	*pre;

	temp = *list;
	while (temp->next != NULL)
	{
		pre = temp;
		temp = temp->next;
	}
	pre->next = NULL;
	temp->next = *list;
	(*list) = temp;
	ft_putstr(s);
}

void	push(t_list **src, t_list **dst, char *s)
{
	t_list	*temp;
	t_list	*temp2;

	if (dst == NULL)
	{
		temp = (*src)->next;
		(*dst) = (*src);
		(*dst)->next = NULL;
		(*src) = temp;
	}
	else
	{
		temp2 = *dst;
		temp = (*src)->next;
		(*dst) = (*src);
		(*dst)->next = temp2;
		(*src) = temp;
	}
	ft_putstr(s);
}
