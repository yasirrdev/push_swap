/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybel-maa <ybel-maa@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 14:05:06 by ybel-maa          #+#    #+#             */
/*   Updated: 2025/12/12 14:08:21 by ybel-maa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_stack *a)
{
	rotate_internal(a);
	ft_printf("ra\n");
}
void	rb(t_stack *b)
{
	rotate_internal(b);
	ft_printf("rb\n");
}
void	rr(t_stack *a, t_stack *b)
{
	rotate_internal(a);
	rotate_internal(b);
	ft_printf("rr\n");
}
