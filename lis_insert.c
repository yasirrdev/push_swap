/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lis_insert.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybel-maa <ybel-maa@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 16:01:40 by ybel-maa          #+#    #+#             */
/*   Updated: 2026/01/16 12:50:50 by ybel-maa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_both(t_stack *a, t_stack *b, int *ca, int *cb)
{
	while (*ca > 0 && *cb > 0)
	{
		rr(a, b);
		(*ca)--;
		(*cb)--;
	}
	while (*ca < 0 && *cb < 0)
	{
		rrr(a, b);
		(*ca)++;
		(*cb)++;
	}
}

void	rotate_single(t_stack *s, int *cost)
{
	while (*cost > 0)
	{
		ra(s);
		(*cost)--;
	}
	while (*cost < 0)
	{
		rra(s);
		(*cost)++;
	}
}

void	insert_back(t_stack *a, t_stack *b)
{
	t_node	*cur;
	t_node	*best;
	int		ca;
	int		cb;
	int		best_cost;

	while (b->size)
	{
		cur = b->top;
		best = cur;
		best_cost = 2147483647;

		while (cur)
		{
			cb = get_cost(get_pos(b, cur->value), b->size);
			ca = get_cost(get_target_pos(a, cur->value), a->size);
			if (ft_abs(ca) + ft_abs(cb) < best_cost)
			{
				best_cost = ft_abs(ca) + ft_abs(cb);
				best = cur;
			}
			cur = cur->next;
		}

		cb = get_cost(get_pos(b, best->value), b->size);
		ca = get_cost(get_target_pos(a, best->value), a->size);

		rotate_both(a, b, &ca, &cb);
		rotate_single(b, &cb);
		rotate_single(a, &ca);
		pa(a, b);
	}
}


