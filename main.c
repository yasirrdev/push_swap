/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybel-maa <ybel-maa@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 11:20:32 by marvin            #+#    #+#             */
/*   Updated: 2026/01/14 12:00:20 by ybel-maa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int argc, char **argv)
{
    t_stack *a;
    t_stack *b;

    if (argc < 2)
        return (0);

    a = parse_args(argc, argv);
    if (!a || is_sorted(a))
        return (0);

    indexing(a);

    b = stack_init();
    push_swap(a, b);

    free_stack(a);
    free_stack(b);
    return (0);
}