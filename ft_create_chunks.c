/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_chunks.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 16:24:42 by judehon           #+#    #+#             */
/*   Updated: 2025/11/25 19:16:49 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int find_chunks_size(int size)
{
    int i;

    i = 20;
    if (i > size)
        i = size;
    while (i >= 2)
    {
        if (size % i == 0)
            return (i);
        i--;
    }
    return (1);
}

t_chunk *ft_create_chunks(int size)
{
    int     nb_chunks;
    int     chunk_size;
    t_chunk *chunks;
    int     i;

    nb_chunks = find_chunks_size(size);
    chunk_size = size / nb_chunks;
    i = 0;
    chunks = malloc(sizeof(t_chunk) * nb_chunks);
    if (!chunks)
        return (NULL);
    while (i < nb_chunks)
    {
        chunks[i].start = i * chunk_size;
        chunks[i].end = (i + 1) * chunk_size - 1;
        i++;
    }
    return (chunks);
}
