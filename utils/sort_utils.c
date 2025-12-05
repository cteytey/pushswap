/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 12:01:51 by judehon           #+#    #+#             */
/*   Updated: 2025/12/05 16:15:41 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	s(stack *a)
{
    int tmp;

    if (a->size < 2)
        return ;
    tmp = a->values[0];
    a->values[0] = a->values[1];
    a->values[1] = tmp;
}

void	ss(stack *a, stack *b)
{
	s(a);
	s(b);
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
	int	top = a->values[0];
	ft_memmove(&a->values[0], &a->values[1], (a->size - 1) * sizeof(int));
	a->values[a->size - 1] = top;
	printf("ra\n");
}
void	rb(stack *b)
{
	if (b->size < 2)
		return;
	int	top = b->values[0];
	ft_memmove(&b->values[0], &b->values[1], (b->size - 1) * sizeof(int));
	b->values[b->size - 1] = top;
	printf("rb\n");
}

void	rr(stack *a, stack *b)
{
	ra(a);
	ra(b);
}

void	rra(stack *a)
{
	if (a->size < 2)
		return;
	int	bot = a->values[a->size - 1];
	ft_memmove(&a->values[1], &a->values[0], (a->size - 1) * sizeof(int));
	a->values[0] = bot;
	printf("rra\n");
}
void	rrb(stack *b)
{
	if (b->size < 2)
		return;
	int	bot = b->values[b->size - 1];
	ft_memmove(&b->values[1], &b->values[0], (b->size - 1) * sizeof(int));
	b->values[0] = bot;
	printf("rrb\n");
}
void	rrr(stack *a, stack *b)
{
	rra(a);
	rrb(b);
}
