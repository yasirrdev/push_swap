/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lis_cost.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybel-maa <ybel-maa@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 16:02:49 by ybel-maa          #+#    #+#             */
/*   Updated: 2026/01/14 16:33:36 by ybel-maa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_pos(t_stack *s, int value)
{
	t_node	*n = s->top;
	int		i = 0;

	while (n)
	{
		if (n->value == value)
			return (i);
		n = n->next;
		i++;
	}
	return (0);
}

int	get_target_pos(t_stack *a, int value)
{
	t_node	*n = a->top;
	int		best = 2147483647;

	while (n)
	{
		if (n->value > value && n->value < best)
			best = n->value;
		n = n->next;
	}
	if (best == 2147483647)
		best = find_min(a);
	return (get_pos(a, best));
}
int	find_min(t_stack *a)
{
	t_node	*current;
	int		min;

	if (!a || !a->top)
		return (0);
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

int	get_cost(int pos, int size)
{
	if (pos <= size / 2)
		return (pos);
	return (pos - size);
}
