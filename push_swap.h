/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judehon <judehon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 12:54:12 by judehon           #+#    #+#             */
/*   Updated: 2025/11/27 14:17:07 by judehon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
#include <stdlib.h>
#include <stdio.h>

// ----------------------- STRUCTURE -----------------------
typedef struct
{
	int		*values;
	int		size;      // nombre d'elements dans le tableau
}			stack;

typedef	struct
{
	int	start;
	int	end;           // chunks pour couper mon tableau en plus petit tableau
}	t_chunk;

// ------------------------- LIBFT -------------------------

char	**ft_split(char const *s, char c);
char	*ft_strjoin(char const *s1, char const *s2);
void	*ft_memmove(void *dest, const void *src, size_t n);
size_t	ft_strlen(char const *str);
int		ft_atoi(const char *nptr);
void	ft_free_all(char **s);

// ---------------------- STACK_UTILS ----------------------

stack	*create_stack(int capacity);
void	delete_stack(stack *s);
int		is_empty(stack *s);
int		push(stack *s, int item);
int		pop(stack *s);

// --------------------- SORTING_UTILS ---------------------

void	s(stack *a);
void	ss(stack *a, stack *b);
void	pa(stack *a, stack *b);
void	pb(stack *b, stack *a);
void	ra(stack *a);
void	rb(stack *b);
void	rr(stack *a, stack *b);
void	rra(stack *a);
void	rrb(stack *b);
void	rrr(stack *a, stack *b);

// ------------------------ PARSING ------------------------

char	**ft_parsing(int ac, char **av);
int		is_valid_number(char **split);
int		is_same_number(char **split);

// ----------------------- ALGORITHM -----------------------

int	*ft_indexizer(int *tab, int size);
int find_chunks_amount(int size);
t_chunk *ft_create_chunks(int size, int *nb_chunks_out);
stack	*ft_push_swap(stack *a);

#endif