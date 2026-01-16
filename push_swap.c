/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybel-maa <ybel-maa@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 11:21:43 by ybel-maa          #+#    #+#             */
/*   Updated: 2026/01/16 12:50:57 by ybel-maa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void push_swap(t_stack *a, t_stack *b)
{
    int *mark;
	int *arr;
	arr = stack_to_array(a);
    if(is_sorted(a))
        return ;
    if (a->size == 2)
        sa(a);
    else if (a->size == 3)
        sort_three(a);
    else if (a->size <= 5)
        sort_five(a, b);
    else
    {
        mark = compute_lis(arr, a->size);
        push_non_lis(a, b, mark, a->size);
        insert_back(a, b);
		normalize_a(a);
        free(mark);
		free(arr);
    }
}
