/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   splite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aferryat <aferryat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 11:44:27 by aferryat          #+#    #+#             */
/*   Updated: 2025/02/09 13:43:55 by aferryat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	count_word(char	*str)
{
	int	word;
	int	i;

	i = 0;
	word = 0;
	while (str[i])
	{
		while (str[i] != ' ' && str[i])
			i++;
		while (str[i] == ' ' && str[i])
			i++;
		word++;
	}
	return (word);
}

void	splite_field(char **new, int j)
{
	while (--j >= 0)
		free(new[j]);
	free (new);
}

static char	*last(int i, int current, char *str)
{
	char	*new;

	new = NULL;
	current = i;
	while (str[current] != ' ' && str[current])
		current++;
	new = new_string(str, current, i);
	return (new);
}

static char	**the_reall_splite(int current, int count, char *str)
{
	char	**new;
	int		i;
	int		j;

	j = 0;
	i = 0;
	new = malloc(sizeof(char *) * (count + 1));
	if (new == NULL)
		return (NULL);
	while (str[i])
	{
		while (str[i] == ' ' && str[i] != '\0')
			i++;
		if (str[i])
		{
			new[j] = last(i, current, str);
			if (new[j] == NULL)
				return (splite_field(new, j), NULL);
			j++;
		}
		while (str[i] != ' ' && str[i] != '\0')
			i++;
	}
	new[j] = NULL;
	return (new);
}

char	**ft_splite(char *str)
{
	char	**new;
	int		count;
	int		current;

	current = 0;
	count = count_word(str);
	new = the_reall_splite(current, count, str);
	return (new);
}
