/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judehon <judehon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 12:54:12 by judehon           #+#    #+#             */
/*   Updated: 2025/11/21 14:09:02 by judehon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
#include <stdlib.h>
#include <stdio.h>
#include "../libft/libft.h"

// ------------------------ STRUCTURE ------------------------
typedef struct
{
	int		*values;
	int		size; // nombre d'elements dans le tableau
}			stack;

// ---------------------- STACK_UTILS ----------------------

stack	*create_stack(int capacity);
void	delete_stack(stack *s);
int		is_full(stack *s);
int		is_empty(stack *s);
int		push(stack *s, int item);
int		pop(stack *s);

// --------------------- SORTING_UTILS ---------------------

void	s(stack *a);
void	ss(stack *a, stack *b);
void	pa(stack *a, stack *b);
void	pb(stack *b, stack *a);
void	rs(stack *s);
void	rr(stack *a, stack *b);
void	rrs(stack *s);
void	rrr(stack *a, stack *b);

// ------------------------ PARSING ------------------------



// ----------------------- ALGORITHM -----------------------



#endif