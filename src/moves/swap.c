/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybel-maa <ybel-maa@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 14:03:10 by ybel-maa          #+#    #+#             */
/*   Updated: 2025/12/12 14:03:12 by ybel-maa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
//				¡¡¡¡¡¡¡¡¡¡¡¡¡REVISA LOS PRINTS!!!!!!!!!!!!!!!!!!!!!!!!
void	sa(t_stack *a)
{
	swap_internal(a);
	ft_printf("sa\n");
}

void	sb(t_stack *b)
{
	swap_internal(b);
	ft_printf("sb\n");
}

void	ss(t_stack *a, t_stack *b)
{
	swap_internal(a);
	swap_internal(b);
	ft_printf("ss\n");
}