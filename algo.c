/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judehon <judehon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 16:26:14 by judehon           #+#    #+#             */
/*   Updated: 2025/12/01 15:26:20 by judehon          ###   ########.fr       */
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

void	sort_chunk(stack *a, stack *b, int start, int end)
{
    while (in_chunk_range(a->values, a->size, start, end))
    {
    	int idx = find_chunk_index(a->values, a->size, start, end);

    	if (idx == a->size - 1)
        {
        pb(b, a);
        if (b->size > 1 && b->values[b->size - 1] < (start + end) / 2)
        	rb(b);
        }
        else
        {
        	int to_top = (a->size - 1) - idx;
        	int to_bot = idx;
        	if (to_top <= to_bot)
            	ra(a);
        	else
            	rra(a);
        }
	}
}

stack	*ft_push_swap(stack *a)
{
    int nb_chunks;
    int c = 0;

    a->values = ft_indexizer(a->values, a->size);
    stack *b = create_stack(a->size);
    t_chunk *chunks = ft_create_chunks(a->size, &nb_chunks);

    while (c < nb_chunks)
    {
		sort_chunk(a, b, chunks[c].start, chunks[c].end);
        c++;
    }
	while (!is_empty(b))
		pa(a, b);
    return (a);
}
