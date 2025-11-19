/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judehon <judehon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 12:01:51 by judehon           #+#    #+#             */
/*   Updated: 2025/11/19 13:49:18 by judehon          ###   ########.fr       */
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
	if (is_empty(s))
		return (0);
	s->values[s->size] = 0;
	s->size--;
	return(1);
}

int	main()
{
	stack *s = create_stack(5);
	if (!s)
	{
		printf("error\n");
		return (1);
	}
	if(s)
		printf("stack has been created\n");
	push(s, 2);
	printf("%d\n", s->size);
	pop(s);
	printf("%d\n", s->size);
	if (is_empty(s))
		printf("stack is empty\n");
	if (is_full(s))
		printf ("stack is full\n");
	delete_stack(s);
}