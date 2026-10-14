/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aferryat <aferryat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 10:55:53 by aferryat          #+#    #+#             */
/*   Updated: 2025/02/13 11:55:23 by aferryat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <unistd.h>
# include <stdlib.h>

typedef struct s_list
{
	int				index;
	int				val;
	int				pos;
	struct s_list	*next;
}	t_list;

void	ft_putstr(char *s);
int		ft_strlen(char *str);
long	ft_atoi(char *str);
char	*new_string(char *str, int max, int start);
char	*ft_string(char **arr_str);
void	start_sort(t_list **stack_a, t_list **stack_b);
void	manager(char *str);
void	start_sort(t_list **stack_a, t_list **stack_b);
int		is_sorted(t_list *list);
char	**ft_splite(char *str);
int		linked_list_size(t_list *list);
void	esy_sort(t_list **list);
void	set_index(t_list *elm, t_list *top);
void	algo(t_list **stack_a, t_list **stack_b);
void	swap_two(t_list **list);
void	swap_a(t_list **list, char *s);
void	rotate(t_list **list, char *s);
void	reverse_rotate(t_list **list, char *s);
void	push(t_list **src, t_list **dst, char *s);
int		ft_mini_sort(t_list *list);
void	splite_field(char **new, int j);
int		is_double(t_list *list);
void	sort_4_5(t_list **stack_a, t_list **stack_b);
void	set_pos(t_list *stack);
int		find_min(t_list *stack);
int		find_min_index(t_list *stack);
#endif