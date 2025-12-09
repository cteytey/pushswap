/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judehon <judehon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 12:01:51 by judehon           #+#    #+#             */
/*   Updated: 2025/12/09 13:45:01 by judehon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sa(stack *a)
{
    int tmp;

    if (a->size < 2)
        return ;
    tmp = a->values[0];
    a->values[0] = a->values[1];
    a->values[1] = tmp;
	printf("sa\n");
}

void	sb(stack *b)
{
    int tmp;

    if (b->size < 2)
        return ;
    tmp = b->values[0];
    b->values[0] = b->values[1];
    b->values[1] = tmp;
	printf("sb\n");
}

void	ss(stack *a, stack *b)
{
	sa(a);
	sb(b);
}

void	pa(stack *a, stack *b)
{
	if (b->size > 0)
		push(a, pop(b));
	printf("pa\n");
}

void	pb(stack *b, stack *a)
{
	if (a->size > 0)
		push(b, pop(a));
	printf("pb\n");
}

void	ra(stack *a)
{
	if (a->size < 2)
		return;
	int i = 0;
	int	first = a->values[0];
	while (i < a->size - 1)
	{
		a->values[i] = a->values[i + 1];
		i++;
	}
	a->values[a->size - 1] = first;
	printf("ra\n");
}
void	rb(stack *b)
{
	if (b->size < 2)
		return;
	int i = 0;
	int	first = b->values[0];
	while (i < b->size - 1)
	{
		b->values[i] = b->values[i + 1];
		i++;
	}
	b->values[b->size - 1] = first;
	printf("rb\n");
}

void	rr(stack *a, stack *b)
{
	ra(a);
	rb(b);
}

void	rra(stack *a)
{
	if (a->size < 2)
		return;
	int last = a->values[a->size - 1];
	int i = a->size - 1;
	while (i > 0)
	{
		a->values[i] = a->values[i - 1];
		i--;
	}
	a->values[0] = last;
	printf("rra\n");
}
void	rrb(stack *b)
{
	if (b->size < 2)
		return;
	int last = b->values[b->size - 1];
	int i = b->size - 1;
	while (i > 0)
	{
		b->values[i] = b->values[i - 1];
		i--;
	}
	b->values[0] = last;
	printf("rrb\n");
}
void	rrr(stack *a, stack *b)
{
	rra(a);
	rrb(b);
}
