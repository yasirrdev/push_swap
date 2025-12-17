/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybel-maa <ybel-maa@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 13:10:14 by ybel-maa          #+#    #+#             */
/*   Updated: 2025/12/12 13:58:55 by ybel-maa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include "../../ft_printf/ft_printf.h"
# include "../../libft/libft.h"
typedef struct s_node
{
	int				value;
	struct s_node	*next;

}					t_node;

typedef struct s_stack
{
	t_node			*top;
	int				size;
}					t_stack;


t_stack *stack_init(void);
void 	stack_push_top(t_stack *stack, int value);
t_node	*node_new(int value);

void	swap_internal(t_stack *s);
void	push_internal(t_stack *dst, t_stack *src);
void	rotate_internal(t_stack *s);
void	reverse_rotate_internal(t_stack *s);

void	sa(t_stack *a);
void	sb(t_stack *b);
void	ss(t_stack *a, t_stack *b);

void	pa(t_stack *a, t_stack *b);
void	pb(t_stack *a, t_stack *b);

void	ra(t_stack *a);
void	rb(t_stack *b);
void	rr(t_stack *a, t_stack *b);

void	rra(t_stack *a);
void	rrb(t_stack *b);
void	rrr(t_stack *a, t_stack *b);

void	push_swap(t_stack *a, t_stack **b);

void	print_error(void);
void	free_stack(t_stack *stack);


#endif