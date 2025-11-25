/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judehon <judehon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 09:36:29 by judehon           #+#    #+#             */
/*   Updated: 2025/11/25 11:21:00 by judehon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

char	**ft_parsing(int ac, char **av)
{
	int     i;
	char    *join;
	char    *tmp;
	char    **split;

	i = 1;
	join = ft_strjoin("", av[i]);
	while (i++ < ac - 1)
	{
		tmp = ft_strjoin(join, av[i]);
		free(join);
		join = tmp;
	}
	split = ft_split(join, ' ');
	free(join);
	if (!split)
		return (NULL);
	if (!is_valid_number(split) || !is_same_number(split))
	{
		ft_free_all(split);
		return (NULL);
	}
	return (split);
}
