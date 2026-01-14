/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybel-maa <ybel-maa@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/21 18:14:05 by ybel-maa          #+#    #+#             */
/*   Updated: 2026/01/14 16:36:26 by ybel-maa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void sort_three(t_stack *a)
{
    int x;
    int y;
    int z; 
    
    x = a->top->value;
    y = a->top->next->value;
    z = a->top->next->next->value;
    if(x > y && y < z && x < z)
        sa(a);
    else if(x > y && y > z)
    {
        sa(a);
        rra(a);
    }
    else if(x > y && y < z && x > z)
        ra(a);
    else if(x < y && y > z && x < z)
    {
        sa(a);
        ra(a);
    }
    else if(x < y && y > z && x > z)
        rra(a);
}

static int find_pos(t_stack *a, int target)
{
    t_node *current;
    int pos;

    current = a->top;
    pos = 0;
    while(current)
    {
        if(current->value == target)
            return (pos);
        current = current->next;
        pos++;
    }
    return (-1);
}
static void    rotate_to_top(t_stack *a, int pos)
{
    if(pos <= a->size / 2)
    {
        while(pos--)
            ra(a);
    }
    else
    {
        pos = a->size - pos;
        while(pos--)
            rra(a);
    }
}
void push_min_to_b(t_stack *a, t_stack *b, int min)
{
    int pos;

    pos = find_pos(a, min);
    rotate_to_top(a, pos);
    pb(a, b);
}

void sort_five(t_stack *a, t_stack *b)
{
    int pushed;

    pushed = 0;
    while(a->size > 3)
    {
        if(a->top->value == 0 || a->top->value == 1)
        {
            pb(a, b);
            pushed++;
        }
        else
            ra(a);
    }
    sort_three(a);
    while(pushed--)
        pa(a, b);
}
    