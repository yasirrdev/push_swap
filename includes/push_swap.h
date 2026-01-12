/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybel-maa <ybel-maa@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 13:10:14 by ybel-maa          #+#    #+#             */
/*   Updated: 2025/12/19 17:05:05 by ybel-maa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../../ft_printf/ft_printf.h"
# include "../../libft/libft.h"
# include <stdlib.h>
# include <unistd.h>

typedef struct s_node
{
	int				value;
	struct s_node	*next;
}	t_node;

typedef struct s_stack
{
	t_node	*top;
	int		size;
}	t_stack;

t_stack	*stack_init(void);
t_node	*node_new(int value);
void	stack_push_top(t_stack *stack, int value);
void	free_stack(t_stack *stack);

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

t_stack	*parse_args(int argc, char **argv);
void	parse_string(char *s, t_stack *a);
void	parse_multiple_args(int argc, char **argv, t_stack *a);

int		is_number(char *s);
int		is_overflow(char *s);
int		check_duplicates(t_stack *a);
void free_split(char **split);
int		is_sorted(t_stack *a);
void	print_error(void);

int		*stack_to_array(t_stack *a);
void	bubble_sort(int *array, int size);
void	index_stack(t_stack *a, int *arr);
void	indexing(t_stack *a);

void	sort_three(t_stack *a);
void	sort_five(t_stack *a, t_stack *b);

int		*compute_lis(int *arr, int size);
int		find_pos(t_stack *a, int target);
void	rotate_to_top(t_stack *a, int pos);
void	sort_lis(t_stack *a, t_stack *b);

void	push_swap(t_stack *a, t_stack *b);

#endif