/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_same_number.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judehon <judehon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 10:22:39 by judehon           #+#    #+#             */
/*   Updated: 2025/11/25 11:19:09 by judehon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	is_same_number(char **split)
{
	int i;
	int j;

	i = 1;
	while (split[i])
	{
		j = 0;
		while (split[j])
		{
			if (ft_atoi(split[i]) == ft_atoi(split[j]) && i != j)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
