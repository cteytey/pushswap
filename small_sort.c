/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judehon <judehon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 12:55:49 by judehon           #+#    #+#             */
/*   Updated: 2025/12/09 14:01:28 by judehon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_3(stack *a)
{
	if (a->values[0] > a->values[1] && a->values[1] < a->values[2] && a->values[2] < a->values[0])
	{ // 2 1 3
		sa(a);
		ra(a);
	}
	else if (a->values[0] < a->values[1] && a->values[1] < a->values[2] && a->values[2] > a->values[0])
	{ // 3 2 1
		sa(a);
		rra(a);
	}
	else if (a->values[0] > a->values[1] && a->values[1] < a->values[2] && a->values[2] > a->values[0])
	{ // 1 3 2
		rra(a);
	}
	else if (a->values[0] < a->values[1] && a->values[1] > a->values[2] && a->values[2] < a->values[0]) // 1 3 2
	{ //1 3 2
		sa(a);
	}
	else if (a->values[0] < a->values[1] && a->values[1] > a->values[2] && a->values[2] > a->values[0])
	{ // 2 3 1
		ra(a);
	}
}
