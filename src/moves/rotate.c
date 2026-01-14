/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybel-maa <ybel-maa@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 14:05:06 by ybel-maa          #+#    #+#             */
/*   Updated: 2026/01/14 11:50:51 by ybel-maa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ra(t_stack *a)
{
	rotate_internal(a);
	write(1, "ra\n", 3);
}
void	rb(t_stack *b)
{
	rotate_internal(b);
	write(1, "rb\n", 3);
}
void	rr(t_stack *a, t_stack *b)
{
	rotate_internal(a);
	rotate_internal(b);
	write(1, "rr\n", 3);
}
