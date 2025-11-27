/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judehon <judehon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 16:26:14 by judehon           #+#    #+#             */
/*   Updated: 2025/11/27 14:17:20 by judehon          ###   ########.fr       */
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

int	find_chunk_index(int *tab,int size, int start, int end)
{
	int	i = size - 1;
	while (i >= 0)
	{
		if (tab[i] >= start && tab[i] <= end)
			return (i);
		i--;
	}
	return (0);
}

stack	*ft_push_swap(stack *a)
{
    int c = 0;
    int nb_chunks;

    a->values = ft_indexizer(a->values, a->size);
    stack *b = create_stack(a->size);
    t_chunk *chunks = ft_create_chunks(a->size, &nb_chunks);

    while (c < nb_chunks)
    {
        int start = chunks[c].start;
        int end = chunks[c].end;

        while (in_chunk_range(a->values, a->size, start, end))
        {
            int idx = find_chunk_index(a->values, a->size, start, end);

            if (idx == a->size - 1) // <-- TOP (values[size-1])
            {
                pb(b, a);          // <-- TA version : push(b, pop(a))
                if (b->size > 1 && b->values[b->size - 1] < (start + end) / 2)
                    rb(b);
            }
            else
            {
                int to_top = (a->size - 1) - idx;  // distance depuis le top
                int to_bot = idx;               // distance depuis le bas

                if (to_top <= to_bot)
                    ra(a);   // rapprocher idx du top
                else
                    rra(a);  // rapprocher idx du top
            }
        }
        c++;
    }
    return b;
}
/*

etape 4 -> chunk++ en gros

etape 5 -> trouver le plus grand element de b, savoir si ra ou rra pour l'amener en haut
une fois qu'il est en haut pa pour le remettre dans a et ainsi de suite.
*/