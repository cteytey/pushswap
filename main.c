/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judehon <judehon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 09:57:59 by judehon           #+#    #+#             */
/*   Updated: 2025/11/25 11:19:31 by judehon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

	rs(a);
	int	i = capacity;
	while (i > 0)					// boucle d'affichage de chaque element d'une stack en les retirant un par un
	{
		printf("%d %d \n", pop(a), pop(b));
		i--;
	}
	delete_stack(a);				// suppression de la stack, free
	delete_stack(b);
}