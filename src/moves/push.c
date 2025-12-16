/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybel-maa <ybel-maa@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 13:57:03 by ybel-maa          #+#    #+#             */
/*   Updated: 2025/12/12 14:04:58 by ybel-maa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_stack *a, t_stack *b)
{
	push_internal(a, b);
	ft_printf("pa\n");
}
void	pb(t_stack *a, t_stack *b)
{
	push_internal(b, a);
	ft_printf("pb\n");
}
