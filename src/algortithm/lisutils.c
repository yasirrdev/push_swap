/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lisutils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 19:31:59 by marvin            #+#    #+#             */
/*   Updated: 2026/01/12 19:31:59 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void shift_mark(int *mark, int size)
{
    int i;
    int first;

    first = mark[0];
    i = 0;
    while (i < size - 1)
    {
        mark[i] = mark[i + 1];
        i++;
    }
    mark[size - 1] = first;
}

void push_non_lis(t_stack *a, t_stack *b, int *mark)
{
    int i;
    int size;

    i = 0;
    size = a->size;
    while (i < size)
    {
        if (mark[0] == 0)
            pb(a, b);
        else
            ra(a);
        shift_mark(mark, size);
        i++;
    }
}

int find_pos(t_stack *a, int value)
{
    t_node *current;
    int pos;

    current = a->top;
    pos = 0;
    while (current)
    {
        if (current->value == value)
            return (pos);
        current = current->next;
        pos++;
    }
    return (-1);
}

int find_min(t_stack *a)
{
    t_node *current;
    int min;

    current = a->top;
    min = current->value;
    while (current)
    {
        if (current->value < min)
            min = current->value;
        current = current->next;
    }
    return (min);
}
int find_target_pos(t_stack *a, int target)
{
    t_node *current;
    int best;

    current = a->top;
    best = 2147483647;
    while (current)
    {
        if (current->value > target && current->value < best)
            best = current->value;
        current = current->next;
    }
    if (best == 2147483647)
        best = find_min(a);
    return find_pos(a, best);
}
void rotate_to_top(t_stack *a, int pos)
{
    if (pos <= a->size / 2)
    {
        while (pos--)
            ra(a);
    }
    else
    {
        pos = a->size - pos;
        while (pos--)
            rra(a);
    }
}
void insert_back(t_stack *a, t_stack *b)
{
    int target_pos;

    while (b->size > 0)
    {
        target_pos = find_target_pos(a, b->top->value);
        rotate_to_top(a, target_pos);
        pa(a, b);
    }
}


