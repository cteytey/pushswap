/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_indexizer.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judehon <judehon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 11:39:13 by judehon           #+#    #+#             */
/*   Updated: 2025/11/25 16:13:09 by judehon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

/*
etape 2 -> creation de chunks de taille n/k (n = valeurs et k = morceaux)

etape 3 -> chunk stack a -> stack b: 
si n <= chunk/2, pb rb et si n>=chunk/2, pb
tri grossier mais debut de tri

etape 4 -> chunk++ en gros

etape 5 -> trouver le plus grand element de b, savoir si ra ou rra pour l'amener en haut
une fois qu'il est en haut pa pour le remettre dans a et ainsi de suite.
*/