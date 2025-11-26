/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_indexizer.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judehon <judehon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 11:39:13 by judehon           #+#    #+#             */
/*   Updated: 2025/11/26 11:59:46 by judehon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	*ft_copy_int_tab(int *tab, int size)
{
	int	i = 0;
	int	*res = malloc(sizeof(int) * size);
	if (!res)
		return (0);
	while (i < size)
	{
		res[i] = tab[i];
		i++;
	}
	return (res);
}

static void	sort_int_tab(int *tab, int size)
{
	int	i;
	int	tmp;

	i = 0;
	while (i < size - 1)
	{
		if (tab[i + 1] < tab[i])
		{
			tmp = tab[i + 1];
			tab[i + 1] = tab[i];
			tab[i] = tmp;
			i = 0;
		}
		else
			i++;
	}
}
int	*ft_indexizer(int *tab, int size)
{
	int	i = 0;
	int	j;
	int	*res = malloc(sizeof(int) * size);
	if (!res)
		return (0);
	int	*tmp = ft_copy_int_tab(tab, size);
	sort_int_tab(tmp, size);
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			if (tab[i] == tmp[j])
			{
				res[i] = j;
				break;
			}
			j++;
		}
		i++;
	}
	free (tmp);
	return (res);
}
