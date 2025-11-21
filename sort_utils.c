/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judehon <judehon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 12:01:51 by judehon           #+#    #+#             */
/*   Updated: 2025/11/21 14:45:45 by judehon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	s(stack *a)
{
	int	tmp1;
	int	tmp2;

	if (a->size <= 1)
		return ;
	tmp1 = pop(a);
	tmp2 = pop(a);
	push(a, tmp1);
	push(a, tmp2);
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
}

void	pb(stack *b, stack *a)
{
	if (a->size > 0)
		push(b, pop(a));
}

void	rs(stack *s)
{
	// int	top = peek(a);

	// ft_memmove(&a->values[1], &a->values[0], (a->size - 1) * sizeof(int));
	// a->values[0] = top;
	int i = 0;
	int	tmp;
	while (i < s->size - 1)
	{
		tmp = s->values[i];
		s->values[i] = s->values[i + 1];
		s->values[i + 1] = tmp;
		i++;
	}
}

void	rr(stack *a, stack *b)
{
	rs(a);
	rs(b);
}

void	rrs(stack *s)
{
	int	bot = s->values[0];

	ft_memmove(&s->values[0], &s->values[1], (s->size - 1) * sizeof(int));
	s->values[s->size - 1] = bot;
	// int i = s->size - 1;
	// int	tmp;
	// while (i > 0)
	// {
	// 	tmp = s->values[i];
	// 	s->values[i] = s->values[i - 1];
	// 	s->values[i - 1] = tmp;
	// 	i--;
	// }
}

void	rrr(stack *a, stack *b)
{
	rrs(a);
	rrs(b);
}
