/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lis.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybel-maa <ybel-maa@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 11:56:08 by ybel-maa          #+#    #+#             */
/*   Updated: 2026/01/14 16:32:52 by ybel-maa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
void	lis_cpy(int *arr, int *len, int *prev, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < i)
		{
			if (arr[j] < arr[i] && len[j] + 1 > len[i])
			{
				len[i] = len[j] + 1;
				prev[i] = j;
			}
			j++;
		}
		i++;
	}
}

int	find_lis_end(int *len, size_t size)
{
	int	i;
	int	max;
	int	index;

	i = 0;
	max = len[0];
	index = 0;
	while (i < (int)size)
	{
		if (len[i] > max)
		{
			max = len[i];
			index = i;
		}
		i++;
	}
	return (index);
}

void	mark_lis(int *mark, int *prev, int index)
{
	while (index != -1)
	{
		mark[index] = 1;
		index = prev[index];
	}
}
static void	init_arrays(int *len, int *prev, int size)
{
	int	i = 0;
	while (i < size)
	{
		len[i] = 1;
		prev[i] = -1;
		i++;
	}
}


int *compute_lis(int *arr, int size)
{
    int *len;
    int *prev;
    int *mark;
    int end;

    len = malloc(sizeof(int) * size);
    prev = malloc(sizeof(int) * size);
    mark = malloc(sizeof(int) * size);
    if(!len || !prev || !mark)
        return (NULL);
    init_arrays(len, prev,  size);
    lis_cpy(arr, len, prev, size);
    end = find_lis_end(len, size);
    mark_lis(mark, prev, end);

    free(len);
    free(prev);
    return (mark);
}
