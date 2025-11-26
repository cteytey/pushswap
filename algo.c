/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judehon <judehon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 16:26:14 by judehon           #+#    #+#             */
/*   Updated: 2025/11/26 16:27:43 by judehon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	in_chunk_range(int *tab,int size, int start, int end)
{
	int	i = 0;
	while (i < size)
	{
		if (tab[i] >= start && tab[i] <= end)
			return (1);
		i++;
	}
	return (0);
}

void	ft_push_swap(stack *a)
{
	int	c = 0;
	int	nb_chunks;
	a->values = ft_indexizer(a->values, a->size);
	stack *b = create_stack(a->size);
	t_chunk *chunks = ft_create_chunks(a->size, &nb_chunks);
	while (c < nb_chunks)
	{
		int	start = chunks[c].start;
		int	end = chunks[c].end;
		while (in_chunk_range(a->values, a->size, start, end))
		{
			int top = a->values[0];
			if (top >= start && top <= end)
			{
				pb(a, b);
				if (b->size > 1 && b->values[0] < (start + end) / 2)
					r(b);
			}
			else
				r(a);
		}
		c++;
	}
}
/*

etape 4 -> chunk++ en gros

etape 5 -> trouver le plus grand element de b, savoir si ra ou rra pour l'amener en haut
une fois qu'il est en haut pa pour le remettre dans a et ainsi de suite.
*/