/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunks_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judehon <judehon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 16:24:42 by judehon           #+#    #+#             */
/*   Updated: 2025/12/12 16:24:01 by judehon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int find_chunks_amount(int size)
{
    int nb;

    if (size <= 1)
        return (1);
    nb = ft_sqrt(size);
    if (nb < 1)
        nb = 1;
    if (nb > 20)
        nb = 20;
    return (nb);
}

t_chunk *ft_create_chunks(int size, int *nb_chunks_out)
{
    int     nb_chunks;
    int     chunk_size;
    t_chunk *chunks;
    int     i;

    nb_chunks = find_chunks_amount(size);
    chunk_size = size / nb_chunks;
    chunks = malloc(sizeof(t_chunk) * nb_chunks);
    if (!chunks)
        return (NULL);
    i = 0;
    while (i < nb_chunks)
    {
        chunks[i].start = i * chunk_size;
        if (i == nb_chunks - 1)
            chunks[i].end = size - 1;
        else
            chunks[i].end = (i + 1) * chunk_size - 1;
        i++;
    }
    *nb_chunks_out = nb_chunks;
    return (chunks);
}
