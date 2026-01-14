/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybel-maa <ybel-maa@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 13:26:27 by ybel-maa          #+#    #+#             */
/*   Updated: 2026/01/14 11:52:16 by ybel-maa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

// Esta funcion cambia los dos primeros nodos del stack.
void	swap_internal(t_stack *s)
{
	t_node	*first;
	t_node	*second;

	if (!s || s->size < 2)
		return ;
	first = s->top;
	second = first->next;
	first->next = second->next;
	second->next = first;
	s->top = second;
}

// Mueve el top de src a dst.
void	push_internal(t_stack *dst, t_stack *src)
{
	t_node	*tmp;

	if (!src || src->size == 0)
		return ;
	tmp = src->top;
	src->top = src->top->next;
	src->size--;
	tmp->next = dst->top;
	dst->top = tmp;
	dst->size++;
}

// Rota el stack hacia arriba, top pasa a bottom.
void	rotate_internal(t_stack *s)
{
	t_node *first;
	t_node *last;
	if (!s || s->size < 2)
		return ;

	first = s->top;
	s->top = first->next;

	last = s->top;

	while (last->next)
		last = last->next;
	last->next = first;
	first->next = NULL;
}

// Rota el stack hacia abajo:, bottom pasa a top

void	reverse_rotate_internal(t_stack *s)
{
	t_node *prev;
	t_node *last;
	
	if (!s || s->size < 2)
		return ;
	prev = NULL;
	last = s->top;

	while(last->next)
	{
		prev = last;
		last = last->next;
	}
	prev->next = NULL;
	last->next = s->top;
	s->top = last;
}
