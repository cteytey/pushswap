/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judehon <judehon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 12:01:51 by judehon           #+#    #+#             */
/*   Updated: 2025/11/20 16:20:42 by judehon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

typedef struct
{
	int		*values;
	int		capacity; // nombre max d'elements possible
	int		size; // nombre d'elements dans le tableau
}			stack;

stack	*create_stack(int capacity)
{
	if (capacity <= 0)
		return (NULL);
	stack *s;
	s = malloc(sizeof(stack));
	if (!s)
		return (NULL);
	s->values = malloc (sizeof(int) * capacity);
	if (!s->values)
	{
		free (s);
		return (NULL);
	}
	s->capacity = capacity;
	s->size = 0;
	return (s);
}

void	delete_stack(stack *s)
{
	free(s->values);
	free(s);
}

int		is_full(stack *s)
{
	if (s->capacity == s->size)
		return (1);
	return (0);
}

int		is_empty(stack *s)
{
	if (s->size == 0)
		return (1);
	return (0);
}

int		push(stack *s, int item) // ajouter un element a la stack
{
	if (is_full(s))
		return (0);
	s->values[s->size] = item;
	s->size++;
	return (1);
}

int		pop(stack *s) // supprimer le dernier element ajouté a la stack
{
	int	popped;
	
	if (is_empty(s))
		return (0);
	popped = s->values[s->size - 1];
	s->size--;
	return (popped);
}

int		peek(stack *s) // montrer la derniere valeur ajoutée a la stack
{
	if (is_empty(s))
		return (0);
	int item = s->values[s->size - 1];
	return (item);
}

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

#include <string.h>

void	rs(stack *s)
{
	// int	top = peek(a);

	// memmove(&a->values[1], &a->values[0], (a->size - 1) * sizeof(int));
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
	// int	bot = a->values[0];

	// memmove(&a->values[0], &a->values[1], (a->size - 1) * sizeof(int));
	// a->values[a->size - 1] = bot;
	int i = s->size - 1;
	int	tmp;
	while (i > 0)
	{
		tmp = s->values[i];
		s->values[i] = s->values[i - 1];
		s->values[i - 1] = tmp;
		i--;
	}
}

void	rrr(stack *a, stack *b)
{
	rrs(a);
	rrs(b);
}

int	main()
{
	int	capacity = 5;
	stack *a = create_stack(capacity); 	// creation d'une stack avec un maximum de 5 valeurs, malloc
	stack *b = create_stack(capacity); 	// creation d'une stack avec un maximum de 5 valeurs, malloc
	if (!a)
	{
		printf("error\n");
		return (1);
	}
	if(a)
		printf("stack has been created\n");

	if (is_empty(a))
		printf("stack is empty\n");

	push(a, 0); 					// ajout d'une valeur "2" en haut de ma stack
	push(a, 1);
	push(a, 2);
	push(a, 3);
	push(a, 4);

	push(b, 5); 					// ajout d'une valeur "2" en haut de ma stack
	push(b, 6);
	push(b, 7);
	push(b, 8);
	push(b, 9);

	rrs(a);
	int	i = capacity;
	while (i > 0)					// boucle d'affichage de chaque element d'une stack en les retirant un par un
	{
		printf("%d %d \n", pop(a), pop(b));
		i--;
	}
	delete_stack(a);				// suppression de la stack, free
	delete_stack(b);
}