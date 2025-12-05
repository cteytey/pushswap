/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 10:14:48 by judehon           #+#    #+#             */
/*   Updated: 2025/12/05 16:24:23 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

stack	*create_stack(int capacity)
{
	if (capacity <= 0)
		return (NULL);
	stack *s;
	s = malloc(sizeof(stack));
	if (!s)
		return (NULL);
	s->values = malloc(sizeof(int) * capacity);
	if (!s->values)
	{
		free (s);
		return (NULL);
	}
	s->size = 0;
	return (s);
}

void	delete_stack(stack *s)
{
	free(s->values);
	free(s);
}

int		is_empty(stack *s)
{
	if (s->size == 0)
		return (1);
	return (0);
}

int		push(stack *s, int item) // ajouter un element a la stack
{
	int i = s->size;
	while (i > 0)
	{
		s->values[i] = s->values[i - 1];
		i--;
	}
	s->values[0] = item;
	s->size++;
	return (1);
}

int		pop(stack *s) // supprimer le dernier element ajouté a la stack
{
	int	popped;
	int	i;
	
	i = 0;
	if (is_empty(s))
		return (0);
	popped = s->values[0];
	while (i < s->size - 1)
	{
		s->values[i] = s->values[i + 1];
		i++;
	}
	s->size--;
	return (popped);
}
