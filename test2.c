/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 12:01:51 by judehon           #+#    #+#             */
/*   Updated: 2025/11/19 15:26:57 by marvin           ###   ########.fr       */
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

int		peek(stack *s) // montrer la derniere valeur ajoutée a la stack
{
	if (is_empty(s))
		return (0);
	int item = s->values[s->size - 1];
	return (item);
}

int	main()
{
	int	capacity = 5;
	stack *s = create_stack(capacity); 	// creation d'une stack avec un maximum de 5 valeurs, malloc
	if (!s)
	{
		printf("error\n");
		return (1);
	}
	if(s)
		printf("stack has been created\n");

	if (is_empty(s))
		printf("stack is empty\n");

	push(s, 2); 					// ajout d'une valeur "2" en haut de ma stack
	printf("%d\n", s->size); 		// verification de la taille + 1 du push

	push(s, 4);
	push(s, 6);
	push(s, 8);
	push(s, 10);
	printf("%d\n", s->size);

	printf("last value of the stack is %d\n", peek(s));
	
	if (is_full(s))
		printf ("stack is full\n");

	int	i = capacity;
	while (i > 0)					// boucle d'affichage de chaque element d'une stack en les retirant un par un
	{
		printf("%d\n", peek(s));
		pop(s);
		i--;
	}
	if (is_empty(s))
		printf("stack is empty");
	delete_stack(s);				// suppression de la stack, free
}