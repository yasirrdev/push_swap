/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybel-maa <ybel-maa@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 13:57:03 by ybel-maa          #+#    #+#             */
/*   Updated: 2026/01/14 11:52:02 by ybel-maa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	pa(t_stack *a, t_stack *b)
{
	push_internal(a, b);
	write(1, "pa\n", 3);
}
void	pb(t_stack *a, t_stack *b)
{
	push_internal(b, a);
	write(1, "pb\n", 3);
}
