/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybel-maa <ybel-maa@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 11:32:20 by ybel-maa          #+#    #+#             */
/*   Updated: 2025/12/22 11:32:20 by ybel-maa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack *stack_init(void)
{
    t_stack *stack;

    stack = (t_stack *)malloc(sizeof(t_stack));
    if (!stack)
        return (NULL);
    stack->top = NULL;
    stack->size = 0;
    return (stack);
}
t_node *node_new(int value)
{
    t_node *new_node;

    new_node = (t_node *)malloc(sizeof(t_node));
    if (!new_node)
        return (NULL);
    new_node->value = value;
    new_node->next = NULL;
    return (new_node);
}
void free_stack(t_stack *stack)
{
    t_node *tmp;

    if(!stack)
        return;
    while(stack->top)
    {
        tmp = stack->top;
        stack->top = stack->top->next;
        free(tmp);
    }
    free(stack);
}
void stack_push_top(t_stack *stack, int value)
{
    t_node *node;

    if(!stack)
        return;
    node = node_new(value);
    if(!node)
        return;
    node->next = stack->top;
    stack->top = node;
    stack->size++;
}
void print_error(void)
{
	write(2, "Error\n", 6);
    exit(1);
}