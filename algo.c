/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judehon <judehon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 16:26:14 by judehon           #+#    #+#             */
/*   Updated: 2025/12/02 16:12:09 by judehon          ###   ########.fr       */
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

int		find_max_index(stack *s)
{
	int max = 0;
	int	i = 1;
	while (i < s->size)
	{
		if (s->values[i] > s->values[max])
			max = i;
		i++;
	}
	return (max);
}
void	b_to_a(stack *a, stack *b, int max)
{
	while (max != b->size - 1)
	{
		int to_top = (b->size - 1) - max;
		int to_bot = max;

		if (to_top <= to_bot)
			rb(b);
		else
			rrb(b);
		max = find_max_index(b);
	}
	pa(a, b);
}

void	b_to_a_chunks(stack *a, stack *b, int start, int end)
{
	while (in_chunk_range(b->values, b->size, start, end))
	{
		int max = find_max_index(b);
		b_to_a(a, b, max);
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
	int	i = nb_chunks - 1;
	while (i >= 0)
	{
		b_to_a_chunks(a, b, chunks[i].start, chunks[i].end);
		i--;
	}
    return (a);
}
