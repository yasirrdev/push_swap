/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybel-maa <ybel-maa@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 11:21:43 by ybel-maa          #+#    #+#             */
/*   Updated: 2025/12/22 11:21:43 by ybel-maa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void push_swap(t_stack *a, t_stack *b)
{
    int *mark;

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
        mark = compute_lis(stack_to_array(a), a->size);
        push_non_lis(a, b, mark);
        insert_back(a, b);
        final_rotate(a);
        free(mark);
    }
}
