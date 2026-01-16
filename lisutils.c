/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lisutils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybel-maa <ybel-maa@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 19:31:59 by marvin            #+#    #+#             */
/*   Updated: 2026/01/16 12:27:40 by ybel-maa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_in_lis(int value, int **lis, int len)
{
	int i;

	i = 0;
	while(i < len)
	{
		if(lis[i] == &value)
			return (1);
		i++;
	}
	return(0);
}
void push_non_lis(t_stack *a, t_stack *b, int *lis, int lis_len)
{
	int i;

	i = a->size;
	while(i--)
	{
		if(!is_in_lis(a->top->value, &lis, lis_len))
			pb(a, b);
		else
			ra(a);		
	}
}


/*void	final_rotate(t_stack *a)
{
	int min;
	int pos;

	min = find_min(a);
	pos = get_pos(a, min);

	if(pos <= a->size / 2)
	{
		while(pos-- > 0)
			ra(a);
	}
	else
	{
		pos = a-> size - pos;
		while(pos-- > 0)
			rra(a);
	}
}
*/