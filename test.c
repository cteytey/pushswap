/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judehon <judehon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 10:14:48 by judehon           #+#    #+#             */
/*   Updated: 2025/11/19 12:01:14 by judehon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct node
{
	int		*value;
	int		max;
}			s_node;

void	show_stack(s_node *s)
{
	int	i = 0;;
	while (i < s->max)
	{
		printf("%d : %d\n", i, s->value[i]);
		i++;
	}
}

int	main()
{
	s_node s;
	
	s.max = 4;
	s.value = malloc(sizeof(int) * s.max);
	if (!s.value)
		return (0);
	s.value[0] = 1;
	s.value[1] = 3;
	s.value[2] = 5;
	s.value[3] = 7;
	show_stack(&s);
	free(s.value);
}