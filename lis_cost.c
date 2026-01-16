/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lis_cost.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybel-maa <ybel-maa@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 16:02:49 by ybel-maa          #+#    #+#             */
/*   Updated: 2026/01/16 12:49:08 by ybel-maa         ###   ########.fr       */
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
int	find_max(t_stack *a)
{
	t_node	*current;
	int		max;

	if (!a || !a->top)
		return (0);
	current = a->top;
	max = current->value;
	while (current)
	{
		if (current->value > max)
			max = current->value;
		current = current->next;
	}
	return (max);
}
void	normalize_a(t_stack *a)
{
	int	pos;

	pos = get_pos(a, find_min(a));
	if (pos <= a->size / 2)
	{
		while (pos-- > 0)
			ra(a);
	}
	else
	{
		pos = a->size - pos;
		while (pos-- > 0)
			rra(a);
	}
}
int get_target_pos(t_stack *a, int value)
{
	t_node	*cur;
	int		best_value;
	int		best_pos;
	int		pos;

	best_value = 2147483647;
	best_pos = 0;
	cur = a->top;
	pos = 0;

	while (cur)
	{
		if (cur->value > value && cur->value < best_value)
		{
			best_value = cur->value;
			best_pos = pos;
		}
		cur = cur->next;
		pos++;
	}

	if (best_value != 2147483647)
		return best_pos;

	// Si no hay ninguno mayor, va antes del mínimo
	return get_pos(a, find_min(a));
}

int	get_cost(int pos, int size)
{
	if (pos <= size / 2)
		return (pos);
	return (pos - size);
}
