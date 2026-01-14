/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lis_insert.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybel-maa <ybel-maa@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 16:01:40 by ybel-maa          #+#    #+#             */
/*   Updated: 2026/01/14 16:31:52 by ybel-maa         ###   ########.fr       */
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

void	rotate_single(t_stack *s, int *c)
{
	while (*c > 0)
	{
		ra(s);
		(*c)--;
	}
	while (*c < 0)
	{
		rra(s);
		(*c)++;
	}
}

void	insert_back(t_stack *a, t_stack *b)
{
	t_node *n;
	int best;
	int ca;
	int cb;

	while (b->size)
	{
		n = b->top;
		best = 2147483647;
		while (n)
		{
			cb = get_cost(get_pos(b, n->value), b->size);
			ca = get_cost(get_target_pos(a, n->value), a->size);
			if (ft_abs(ca) + ft_abs(cb) < best)
				best = ft_abs(ca) + ft_abs(cb);
			n = n->next;
		}
		cb = get_cost(get_pos(b, b->top->value), b->size);
		ca = get_cost(get_target_pos(a, b->top->value), a->size);
		rotate_both(a, b, &ca, &cb);
		rotate_single(b, &cb);
		rotate_single(a, &ca);
		pa(a, b);
	}
}
