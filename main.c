/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judehon <judehon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 09:57:59 by judehon           #+#    #+#             */
/*   Updated: 2025/11/27 15:59:51 by judehon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


int	main(int ac, char **av)
{
    char **args = ft_parsing(ac, av);
	int size = 0;
	while (args[size])
		size++;
    stack *a = create_stack(size);

	int	i = 0;
    while (i < size)
	{
        push(a, ft_atoi(args[i]));
		i++;
	}
    ft_push_swap(a);
    while (i > 0)
	{
        printf("%d\n", pop(a));
		i--;
	}
	return (0);
}